#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
Create a library of contract check statements from the given template.

Usage:
    create-contract-lib.py [--base-name=DIR] [ --prefix=PREFIX]
                           [ --expect-name=NAME --ensure-name=NAME --assert-name=NAME]
                           [--verbatim --quiet] <template>
    create-contract-lib.py (-h | --help)
    create-contract-lib.py --version

Arguments:
    <template>            The path to the directory containing the template.

Options:
    --base-name=NAME      The base name to use. The created contract library will be
                            put in a directory named by prefixing the base name with PREFIX.
                          [default: contract]
    --prefix=PREFIX       The prefix to use. [default: ]
    --expect-name=NAME    Name to use for precondition macro. Will be converted to uppercase
                            unless --verbatim is given. [default: EXPECT]
    --ensure-name=NAME    Name to use for postcondition macro. Will be converted to uppercase
                            unless --verbatim is given. [default: ENSURE]
    --assert-name=NAME    Name to use for the 'assert' macro. Will be converted to uppercase
                            unless --verbatim is given. [default: ASSERT]
    --verbatim            Do not transform PREFIX to uppercase when used in macro names.
    --quiet               Silent operation.
    --version             Outputs version information.
    -h  --help            Shows the help screen.
"""
try:
    from docopt import docopt  # Creating command-line interface
except ImportError:
    sys.stderr.write("""
        %s is not installed: this program won't run correctly.
        """ % ("docopt"))

import re
import os
import time
from shutil import copytree, ignore_patterns, move, Error
from sys import argv

autogen_notice_template = """This file was automatically generated from libcontract
 * (https://github.com/fblomqvi/libcontract) at
 *
 *     {}
 *
 * with the following command:
 *
 *     {}"""

def rename_files_if_needed(prefix, dest_dir):
    if prefix:
        base = "{}/include/{}contract"
        move(base.format(dest_dir, ""), base.format(dest_dir, prefix))

        fname = "{}/{}contract.pc.in".format(dest_dir, "{}")
        move(fname.format(""), fname.format(prefix))

def replace_in_file(filepath, regex, replacements):
    fin = open(filepath, "r")
    text = fin.read()

    # For each match, look up the corresponding value in the dictionary
    text = regex.sub(lambda match: replacements[match.group(0)], text)
    fin.close()

    fin = open(filepath, "w")
    fin.write(text)
    fin.close()

def get_autogen_notice():
    now = time.strftime('%Y-%m-%d %H:%M:%S %z', time.gmtime())
    return autogen_notice_template.format(now, " ".join(argv))

def replace_placeholders(dest_dir, args):
    replacements = {
        "$PREFIX$" : args["--prefix"],
        "$EXPECT$" : args["--expect-name"],
        "$ENSURE$" : args["--ensure-name"],
        "$ASSERT$" : args["--assert-name"],
    }

    if not args["--verbatim"]:
        replacements.update({k : v.upper() for (k, v) in replacements.items()})

    replacements["$prefix$"] = args["--prefix"]
    replacements["$autogen_notice$"] = get_autogen_notice()

    # Create a regular expression from all of the dictionary keys
    regex = re.compile("|".join(map(re.escape, replacements.keys( ))))

    for dirname, _, files in os.walk(dest_dir):
        for filename in files:
            filepath = os.path.join(dirname, filename)
            replace_in_file(filepath, regex, replacements)

def main():
    args = docopt(__doc__, version="check-lib 0.1")
    template_dir = args["<template>"]
    prefix = args["--prefix"]
    dest_dir = prefix + args["--base-name"]

    if not args["--quiet"]:
        print("Creating CCS library...")
        print("  Using template dir: {}".format(template_dir))
        print("  Using prefix: {}".format(prefix))
        print("  Destination dir: {}".format(dest_dir))

    try:
        copytree(template_dir, dest_dir, ignore=ignore_patterns('.git', '*.swp'))
        rename_files_if_needed(prefix, dest_dir)
        replace_placeholders(dest_dir, args)
    except FileExistsError as err:
        print("Error: Destination directory '{}' already exists!".format(dest_dir))
    else:
        if not args["--quiet"]:
            print("Done")


if __name__ == "__main__":
    main()
