
#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#define NULL ((void *)0) //null--> void pointer casting to zero to initialize the pointer avoiding wild pointers

/*define structure to be the data of the student*/
typedef struct {
	int id; 		/*student id*/
	char name[50];  /*student name*/
	int age;		/*student age*/
	float gpa;		/*student gpa*/

}student;

/*define a structure to be represented as a node in linked list*/
typedef struct node{
	student data;
	struct node * next;
}node;

node* head=NULL; //pointer to first node in linked list to track the list


/********functions declaration ******************************/
//This function collects new student details from the user and adds them to the student linked list.
void addStudent(const  student *const ptr);
//This function displays the details of all students currently in the system.
void displayStudents(void);
//This function searches for a student by their ID and displays their details if found.
void searchStudentByID(int id);
//This function updates the details of a student with the given ID.
void updateStudent(int id);
//This function calculates and returns ethe average GPA of all students.
float calculateAverageGPA(void);
//This function finds and displays the student with the highest GPA
void searchHighestGPA(void);
//This function deletes a student from the linked list by their ID
void deleteStudent(int id);



int main(void){
	setvbuf(stdout,NULL,_IONBF,0);
	setvbuf(stderr,NULL,_IONBF,0);
	//declaring all the variables at the begining
	int choice=0,exit=0;
	student s1;

	while (1){
		/*displays the menu options to the user, takes the user's choice as input*/
		printf("Menu Options:\n");
		printf("1)Add a Student\n");
		printf("2)Display All Students:\n");
		printf("3)Search for a Student by ID\n");
		printf("4)Update Student Information\n");
		printf("5)Delete a Student\n");
		printf("6)Calculate Average GPA:\n");
		printf("7)Find Student with Highest GPA\n");
		printf("8)Exit\n");
		printf("enter your choice ");
		scanf("%d",&choice);
		printf("----------------------------------------------------------------------------\n");
		switch(choice){
		case 1:
			printf("enter the student information:");
			printf("\nenter student name :");
			scanf("%s",s1.name);
			printf("\nenter student id :");
			scanf("%d",&s1.id);
			printf("\nenter student age :");
			scanf("%d",&s1.age);
			printf("\nenter student gpa :");
			scanf("%f",&s1.gpa);
			addStudent(&s1);
			printf("----------------------------------------------------------------------------\n");
			break;
		case 2:
			displayStudents();
			printf("----------------------------------------------------------------------------\n");
			break;
		case 3:
			printf("enter student id :");
			scanf("%d",&s1.id);
			searchStudentByID(s1.id);
			printf("----------------------------------------------------------------------------\n");
			break;
		case 4:
			printf("enter student id :");
			scanf("%d",&s1.id);
			updateStudent(s1.id);
			printf("----------------------------------------------------------------------------\n");
			break;
		case 5:
			printf("enter student id :");
			scanf("%d",&s1.id);
			deleteStudent(s1.id);
			printf("----------------------------------------------------------------------------\n");
			break;
		case 6:
			printf("the average gpa = %f\n",calculateAverageGPA());
			printf("----------------------------------------------------------------------------\n");
			break;
		case 7:
			searchHighestGPA();
			printf("----------------------------------------------------------------------------\n");
			break;
		case 8:
			exit=1;
			break;
		default:
			printf("invalid option \n");
			printf("----------------------------------------------------------------------------\n");
			break;
		}
		if(exit)
		{ printf("GOODBYE ");
			break;
		}
	}
	return 0;
}




/**************functions implementation ******************************/
void addStudent(const  student *const ptr){
	//pointer to loop along the list
	node * loop = head;


	//check if the id exists
	while(loop!=NULL){
		if(loop->data.id==ptr->id){
			printf("ERROR: ID already exists\n");
			return;
		}
		loop=loop->next;
	}
	//id doesnt exists so we can allocate new node
	node* link= (node*)malloc(sizeof(node));
	//check if memory allocation fails
	assert(link != NULL);

	link->data.id=ptr->id;
	link->data.age=ptr->age;
	link->data.gpa=ptr->gpa;
	link->next=NULL;
	strcpy(link->data.name,ptr->name);
	if(head==NULL){
		//the list is empty
		head=link;
		return;
	}
	loop=head;
	while(loop->next!=NULL){
		loop=loop->next;
	}
	loop->next=link;

}


void displayStudents(void){
	//check if the list is empty
	if(head==NULL){
		printf("the list is empty \n");
		return;
	}
	node * loop=head;
	while(loop!=NULL){
		printf("{student name: %s   ",loop->data.name);
		printf(" student id: %d   ",loop->data.id);
		printf(" student age: %d   ",loop->data.age);
		printf(" student gpa: %f}\n",loop->data.gpa);
		printf(" \n");
		loop=loop->next;
	}
}

void searchStudentByID(int id){
	//check if the list is empty
	if(head==NULL){
		printf("the list is empty \n");
		return;
	}
	/*since the list is not empty we loop along the list untill
	 *we find the id or the list is finshed*/
	node * loop=head;
	//note: we dont terminate using the data inside the list
	while(loop!=NULL){
		if(loop->data.id==id){
			//student is found by the id
			//show the data of the student
			printf("student is found\n");
			printf(" student name: %s\n",loop->data.name);
			printf(" student id: %d\n",loop->data.id);
			printf(" student age: %d\n",loop->data.age);
			printf(" student gpa: %f\n",loop->data.gpa);
			return;
		}
		//go to the next node
		loop=loop->next;
	}
	//we looped along all the list and we didnt found the student id
	printf("student is not found \n");
	return;

}


void updateStudent(int id){
	//check if the list is empty
	if(head==NULL){
		printf("the list is empty \n");
		return;
	}
	/*since the list is not empty we loop along the list untill
	 *we find the id or the list is finshed*/
	node * loop=head;
	//note: we dont terminate using the data inside the list
	while(loop!=NULL){
		if(loop->data.id==id){
			//student is found by the id
			//update the student data
			printf("enter the new details for student with Id : %d \n",id);
			printf("enter the new name\n");
			scanf("%s",loop->data.name);
			printf(" enter the new age\n");
			scanf("%d",&loop->data.age);
			printf("enter the new gpa\n");
			scanf("%f",&loop->data.gpa);
			printf("student details updated successfully  \n");
			return;
		}
		//go to the next node
		loop=loop->next;
	}
	//if we reached here we have looped along the list and we didnt find the id
	printf("student with ID %d is not found \n",id);
	return;
}



float calculateAverageGPA(void){
	//handle the case if the list is empty
	if(head==NULL){
		printf("the list is empty \n");
		return 0.0;
	}
	//start looping along the list
	node * loop=head;
	int count=0;// for number of nodes
	float total_gpa=0.0; // summation of gpa
	while(loop!=NULL){
		total_gpa+=loop->data.gpa;
		count++;
		loop=loop->next;
	}
	//we have looped along all the list
	if(count){
		return(total_gpa/count);}
	else
		return 0.0;


}



void searchHighestGPA(void){
	//handle the case if the list is empty
	if(head==NULL){
		printf("the list is empty \n");
		return;
	}
	/*****only one node exist************/
	if(head->next==NULL){
		printf("student with highest gpa:\n");
		printf(" student name: %s\n",(*head).data.name);
		printf(" student id: %d\n",(*head).data.id);
		printf(" student age: %d\n",(*head).data.age);
		printf(" student gpa: %f\n",(*head).data.gpa);
		return;
	}
	//start looping along the list
	node * loop=head->next;
	node * max_ptr=head;//will refer to the node with highest gpa
	while(loop!=NULL){
		//check if the current node contain gpa higher than the max
		if((*max_ptr).data.gpa<loop->data.gpa){
			max_ptr=loop;
		}
		//go to the next node
		loop=loop->next;

	}
	//print info of the node with max gpa
	printf("student with highest gpa:\n");
	printf(" student name: %s\n",(*max_ptr).data.name);
	printf(" student id: %d\n",(*max_ptr).data.id);
	printf(" student age: %d\n",(*max_ptr).data.age);
	printf(" student gpa: %f\n",(*max_ptr).data.gpa);
	return;
}






void deleteStudent(int id) {
	//handle the case if the list is empty
	if (head == NULL) {
		printf("The list is empty \n");
		return;
	}

	// Handle the case where the head node needs to be deleted
	if (head->data.id == id) {
		node *temp = head;
		head = head->next; // Move the head to the next node
		free(temp);        // Free the old head node
		printf("Student with ID %d deleted.\n", id);
		return;
	}

	node *current = head->next;
	node *prev = head;

	// Traverse the list to find the node before the one to delete
	while(current!=NULL){
		if(current->data.id==id){
			//student is found
			prev->next=current->next;
			free(current);
			printf("Student with ID %d deleted.\n", id);
			return;
		}
		//move to the next node
		current = current->next;
		prev = prev->next;
	}
	//we passed along the list and id is not found
	printf("Student with ID %d does not exist \n", id);
	return;
}







