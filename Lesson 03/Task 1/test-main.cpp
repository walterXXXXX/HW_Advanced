#pragma once

#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "List.cpp"


TEST_CASE("Class: List. Test method: bool Empty()", "[List.empty]") {

	List testList; //создали тестовый список
	
	SECTION("for empty list") {
		INFO("Тестовый список пока что пуст");
		CHECK(testList.Empty() == true);
	}

	SECTION("for not empty list") {
		testList.PushBack(10); // добавим элемент в список
		INFO("В тестовый список не пустой");
		CHECK(testList.Empty() == false);
	}

}

TEST_CASE("Class: List. Test method: unsigned long Size()", "List.size") {

	List testList; //создали тестовый список

	SECTION("for empty list") {
		INFO("Тестовый список пока что пуст");
		CHECK(testList.Size() == 0);
	}

	SECTION("for not empty list") {
		testList.PushBack(10); // добавим элемент в список
		INFO("Размер списка не соответствует кол-ву добавленных элементов");
		REQUIRE(testList.Size() == 1);
		testList.PushBack(20);
		REQUIRE(testList.Size() == 2);
		testList.PushFront(50);
		CHECK(testList.Size() == 3);
	}

}

TEST_CASE("Class: List. Test method: void Clear()","List.clear") {

	List testList; //создали тестовый список
	testList.PushBack(10); // добавим элемент в список
	testList.PushFront(40); // добавим элемент в список
	testList.Clear();

	INFO("Размер списка не обнулился после очистки");
	CHECK(testList.Size() == 0);

}

int main() {
	setlocale(LC_ALL, "Russian");
	return Catch::Session().run();
}