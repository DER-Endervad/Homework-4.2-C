#pragma once
#include <iostream>
#include <fstream>
class address
{
private:
	std::string city;
	std::string street;
	int home;
	int apartment;

public:
	address() {
		city = "city";
		street = "street";
		home = 0;
		apartment = 0;
	}

	void full(std::ifstream& file) {
		file >> city;
		file >> street;
		file >> home;
		file >> apartment;
		file.clear();
	}

	void sort(address* arr, const int size) {
		bool swap = false;
		do {
			swap = false;
			for (int i = 1; i < size; ++i) {
				if (arr[i - 1].city > arr[i].city) {
					address temp = arr[i - 1];
					arr[i - 1] = arr[i];
					arr[i] = temp;
					swap = true;
				}
				else if (arr[i - 1].city == arr[i].city) {
					if (arr[i - 1].street > arr[i].street) {
						address temp = arr[i - 1];
						arr[i - 1] = arr[i];
						arr[i] = temp;
						swap = true;
					}
					else if (arr[i - 1].street == arr[i].street) {
						if (arr[i - 1].home > arr[i].home) {
							address temp = arr[i - 1];
							arr[i - 1] = arr[i];
							arr[i] = temp;
							swap = true;
						}
						else if (arr[i - 1].home == arr[i].home) {
							if (arr[i - 1].apartment > arr[i].apartment) {
								address temp = arr[i - 1];
								arr[i - 1] = arr[i];
								arr[i] = temp;
								swap = true;
							}
						}
					}
				}
			}
		} while (swap);
	}

	void output(std::ofstream& out) {
		out << city; out << ", ";
		out << street; out << ", ";
		out << home; out << ", ";
		out << apartment; out << "\n";
		out.clear();
	}
};

