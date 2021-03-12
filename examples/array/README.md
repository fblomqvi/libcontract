Build instructions:

    # in libcontract root dir
    ./create_contract_lib.py std-template/
    cp -r contract/ examples/array/

    cd examples/array

    mkdir build && cd build
    cmake ..
    make
