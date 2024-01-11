#pragma once

#include "catch2/catch_test_macros.hpp"
#include "catch2/catch_session.hpp"
#include "List.cpp"


TEST_CASE("Class: List. Basic tests", "[basic_tests]") {

	List testList; //создали тестовый список
	int testBackVal = 10; // тестовое значение величины в конце списка
	testList.PushBack(testBackVal);
	
	SECTION("PushBack method") {
		INFO("В тестовый список был добавлен один элемент");
		CHECK(testList.Empty() == false);
		CHECK(testList.Size() == 1);
	}

	int testFrontVal = 20; // тестовое значение величины в начале списка
	testList.PushFront(testFrontVal);

	SECTION("PushFront method") {
		INFO("В тестовый список было добавлено два элемента");
		CHECK(testList.Empty() == false);
		CHECK(testList.Size() == 2);
	}

	SECTION("PopBack method") {
		INFO("Ошибка при извлечении в конце списка");
		CHECK(testList.PopBack() == testBackVal);
		CHECK(testList.PopBack() == testFrontVal);
		REQUIRE(testList.Size() == 0);
		// если список пуст, пробуем вызвать метод PopBack и тестируем корректную обработку исключения
		try {
			testList.PopBack();
		}
		catch (const std::runtime_error& e) {
			CHECK(!std::strcmp(e.what(), "list is empty"));
		}
		
	}

	SECTION("PopFront method") {
		INFO("Ошибка при извлечении в начале списка");
		CHECK(testList.PopFront() == testFrontVal);
		CHECK(testList.PopFront() == testBackVal);
		REQUIRE(testList.Size() == 0);
		// если список пуст, пробуем вызвать метод PopFront и тестируем корректную обработку исключения
		try {
			testList.PopFront();
		}
		catch (const std::runtime_error& e) {
			CHECK(!std::strcmp(e.what(), "list is empty"));
		}
	}

}

TEST_CASE("Class: List. Advanced tests", "[advanced_tests]") {
	// тест по сценарию: добавляем три элемента в начало списка, считываем их с конца и наоборот

	List testList; //создали тестовый список
	int t1 = 10; int t2 = 20; int t3 = 30; // тестовые значения

	SECTION("PushFront/PopBack test", "[PushFornt_PopBack]") {
		INFO("Ошибка в сценарии добавления элементов в начало списка, а считываня с конца");
		testList.PushFront(t1);
		testList.PushFront(t2);
		testList.PushFront(t3);
		CHECK(testList.Size() == 3);
		CHECK(testList.PopBack() == t1);
		CHECK(testList.PopBack() == t2);
		CHECK(testList.PopBack() == t3);
		CHECK(testList.Size() == 0);
	}

	SECTION("PushBack/PopFront test", "[PushBack_PopFront]") {
		INFO("Ошибка в сценарии добавления элементов в конец списка, а считываня с начала");
		testList.PushBack(t1);
		testList.PushBack(t2);
		testList.PushBack(t3);
		CHECK(testList.Size() == 3);
		CHECK(testList.PopBack() == t3);
		CHECK(testList.PopBack() == t2);
		CHECK(testList.PopBack() == t1);
		CHECK(testList.Size() == 0);
	}

}


int main() {
	setlocale(LC_ALL, "Russian");
	return Catch::Session().run();
}