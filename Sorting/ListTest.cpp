#include "List.h"

int main(){
	std::cout << "---ListTest Begin---\n";
	List test_List_One = List();
	std::cout << test_List_One;
	test_List_One.append(5);	
	std::cout << test_List_One;
	for(int i = 0; i<100;i++){
		test_List_One.append(i);
	}
	std::cout << test_List_One;	
    	return 0;
}

