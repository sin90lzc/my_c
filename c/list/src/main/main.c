/**
 * 该程序用于测试c链表原理
 *
 */
#include <stdio.h>
#include <assert.h>
#include <list.h>
#include <student.h>

void assertList3(__const STUDENT * first,__const STUDENT * second,__const STUDENT * third){
	//first的下一个节点是second
	assert(first->list.next==(&second->list));

	//second的下一个节点是third
	assert(second->list.next==(&third->list));

	//third的下一个节点是first
	assert(third->list.next==(&first->list));

	//third的上一个节点是second
	assert(third->list.prev==(&second->list));

	//second的上一个节点是first
	assert(second->list.prev==(&first->list));

	//first的上一个节点是third
	assert(first->list.prev==(&third->list));
}

void assertList2( __const STUDENT  * first,__const STUDENT *  second){

	//first的下一个节点是second
	assert(first->list.next==(&second->list));

	//second的下一个节点是first
	assert(second->list.next==(&first->list));

	//second的上一个节点是first
	assert(second->list.prev==(&first->list));

	//first的上一个节点是second
	assert(first->list.prev==(&second->list));

}
int main(int argc,char ** argv){
	//初始化链表student_list
	LIST_HEAD(student_list);

	STUDENT tim={student_list,"tim",28}; //注意student_list是值传递，非地址传递
	STUDENT rain={student_list,"rain",28};//注意student_list是值传递，非地址传递
	STUDENT mia={student_list,"mia",28};//注意student_list是值传递，非地址传递

	printf("------------test add after--------------\n");

	INIT_LIST_HEAD(&tim.list);//第一个节点的next与prev必须指向自身，才能形成链表的闭环。

	//链表的顺序为：tim<->rain<->mia，链表第一个节点是tim，最后一个节点是mia
	list_add(&rain.list,&tim.list);
	list_add(&mia.list,&rain.list);
	
	assertList3(&tim,&rain,&mia);

	//根据链表节点获取其对应的结构体地址。
	STUDENT * rain_point=list_entry(tim.list.next,STUDENT,list);
	STUDENT * mia_point=list_entry(tim.list.next->next,STUDENT,list);
	STUDENT * tim_point=list_entry(rain.list.prev,STUDENT,list);
	
	assert(rain_point==(&rain));

	printf("rain's name:%s\n",rain_point->name);

	assert(mia_point==(&mia));

	printf("mia's name:%s\n",mia_point->name);

	assert(tim_point==(&tim));

	printf("tim's name:%s\n",tim_point->name);

	printf("-----------test del------------\n");

	//删除mia节点后，链表变成是这样tim<->rain
	list_del(&mia.list);

	assertList2(&tim,&rain);

	printf("-------------test add before-------------\n");

	//在tim节点前插入节点mia，链表变成是这样了mia<->tim<->rain
	list_add_tail(&mia.list,&tim.list);	

	assertList3(&mia,&tim,&rain);
	
	printf("---------------test replace----------------\n");

	STUDENT replace={student_list,"replace",28};

	//用replace节点替换tim节点,链表变成是这样了mia<->replace<->rain
	list_replace(&tim.list,&replace.list);
		
	assertList3(&mia,&replace,&rain);

	//用tim节点替换replace节点,链表变成是这样了mia<->tim<->rain
	list_replace(&replace.list,&tim.list);

	assertList3(&mia,&tim,&rain);

	printf("---------test move----------------\n");

	//将mia节点移动至rain节点后面，链表变成是这样了tim<->rain<->mia
	list_move(&mia.list,&rain.list);	

	assertList3(&tim,&rain,&mia);
		
	printf("----------test rotate----------------\n");

	//将mia节点与其之后的节点（即tim节点）交换位置，链表变成是这样：mia<->rain<->tim
	list_rotate_left(&mia.list);
	
	assertList3(&mia,&rain,&tim);

	printf("--------------test islast--------------\n");		

	int islast=list_is_last(&tim.list,&mia.list);

	//tim节点是最后一个节点
	assert(islast);

	int notlast=list_is_last(&rain.list,&mia.list);

	//rain节点不是最后一个节点
	assert(!notlast);

	return 0;
}

