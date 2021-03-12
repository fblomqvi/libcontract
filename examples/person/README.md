Build instructions:

    # in libcontract root dir
    ./create_contract_lib.py std-template/
    cp contract/src/contract.c examples/person/src
    mkdir examples/person/src/contract
    cp contract/include/contract/{contract,ut/framework,ut/CppUTest}.h examples/person/src/contract

    cd examples/person

    mkdir build && cd build
    cmake ..
    make
