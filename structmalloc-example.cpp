#include "m_struct.h"
#include <iostream>
#include <cstdlib>

int main(){
	BTNode BT1;
	BTNode *BT2;
	BT2 = (BTNode*)malloc(sizeof(BTNode));
	std::cout<<"size of BT1 is"<<sizeof(BT1)<<std::endl;
	std::cout<<"size of BT2 is"<<sizeof(*BT2)<<std::endl;
	return 0;
}
