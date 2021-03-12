find_package(CppUTest)

add_executable(test_person test_person.cc)

target_link_libraries(test_person
    PRIVATE
	CppUTest
	contract
	person
)

add_test(NAME TestPerson COMMAND test_person)
