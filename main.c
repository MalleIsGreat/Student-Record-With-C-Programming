/*

NB: comments where added as a means to ease navigating throughout the code.
Name: Obase Emmanuel
Class: Software Engeneering level two(2)

*/
#include <stdio.h>
#include <stdlib.h>
// creating an instance of name MAX
#define MAX 100
#define SUBJECTS 5
// student structure
struct student {
	char name[20];
    int subjects[SUBJECTS];
	int id;
	float adverageMarks;
	int age;
};
// here the structure was called and given [max] to create 100 instancese of students structure
struct student students[MAX];
int size =0;

// procedure to add students
void addStudent() {
	int total;
	struct student name;
	if(size < MAX) {
		printf("Enter Students ID: ");
		scanf("%d",&name.id);
		for(int i=0; i<size; i++){
			if(name.id == students[i].id){
				printf("Student ID Already Existing\n");
				return;
			}
		}
		printf("Enter Students Name: ");
		scanf("%s",&name.name);
		printf("Enter Students Age: ");
		scanf("%d",&name.age);
		printf("Enter Marks For Courses\n");
		printf("----------------------\n");
		printf("Algorithm: ");
		scanf("%d",&name.subjects[0]);
		printf("Maths: ");
		scanf("%d",&name.subjects[1]);
		printf("Web_Programing: ");
		scanf("%d",&name.subjects[2]);
		printf("Digital_Litracy: ");
		scanf("%d",&name.subjects[3]);
		printf("Computer Architecture: ");
		scanf("%d",&name.subjects[4]);
		for(int i=0; i<5; i++){
			total+=name.subjects[i];
		}
		name.adverageMarks = total/5;
		students[size]=name;
		size++;
		printf("Student Added Successfully!\n");
	} else {
		printf("Record Size Full\n");
	}
}

// procedue to display students
void showStudents() {
	if(size ==0) {
		printf("No Student Has Been Recorded Yet!\n");
	} else {
		printf("ID\t Names\t Age\t Algo\t Maths\t Web_p\t Di_Lit\t Comp_A\t Adverage\n");
		printf("--------------------------------------------------------------------------------------------------\n");
		for(int i=0; i<size; i++) {
			printf("%d\t %s\t %d\t", students[i].id,students[i].name,students[i].age);
			for(int j=0; j<5; j++){
				printf("%d\t",students[i].subjects[j]);
			}
			printf("%.2f\n",students[i].adverageMarks);
		}
	}
}

// procedue to display students
void search() {
	int id;
	printf("Enter Student ID To Search: ");
	scanf("%d",&id);
	for(int i=0; i<size; i++) {
		if(students[i].id == id) {
			printf("Student Id = %d\t Name = %s    Adverage = %.2f\n", students[i].id,students[i].name,students[i].adverageMarks);
			return;
		}
	}
	printf("Student Not Found\n");
}

// procedue to sort students
void sort_id(){
struct student tmp;
for(int i=0; i<size-1; i++){
	for(int j=size; j>i+1;j--){
		if(students[j].id>students[j-1].id){
			tmp = students[j-1];
			students[j-1]=students[j];
			students[j]=tmp;
		}
	}
}
}
void sort_grade(){
struct student tmp;
for(int i=0; i<size-1; i++){
	for(int j=size; j>i+1;j--){
		if(students[j].adverageMarks>students[j-1].adverageMarks){
			tmp = students[j-1];
			students[j-1]=students[j];
			students[j]=tmp;
		}
	}
}
}

//procedue to get computed adverage
void adverage() {
	if(size > 0) {
		float total;
		for(int i=0; i<size; i++) {
			total +=students[i].adverageMarks;
		}
		printf("Total Overall Adverage = %.2f",total/size);
	} else {
		printf("No Adverage Was Found");
	}
}

// procedue to get the top performer
void topPerformer() {
	struct student e;
	if(size>0) {
		e=students[0];
		for(int i=1; i<size; i++){
			if(students[i].adverageMarks>e.adverageMarks){
			 e=students[i];   
			}
		}
		printf("Student Name = %s\t Adeverage = %.2f\n",e.name,e.adverageMarks);
	} else {
		printf("No Student Record Was Found\n");
	}
}

// procedue to filter students
void filter() {
	int option;
	printf("Choose 1. Filter Grades Based On <input (lower threshold) | 2. Based On >Input (higher threshold)\n");
	printf("------------------------------------------------------\n");
	printf("Enter Option: ");
	scanf("%d",&option);
	if(option == 1) {
		int tmp;
		printf("Grades Lower Than <: ");
		scanf("%d",&tmp);
		printf("ID\t Names\t Age\t Adverage\n");
		for(int i=0; i<=size; i++) {
			if(students[i].adverageMarks<tmp) {
				printf("%d\t %s\t %d\t %.2f\n",students[i].id,students[i].name,students[i].age,students[i].adverageMarks);
			}
		}
	} else if(option ==2) {
		int tmp;
		printf("Grades Greater Than >: ");
		scanf("%d",&tmp);
		printf("ID\t Names\t Age\t Adverage\n");
		for(int i=0; i<=size; i++) {
			if(students[i].adverageMarks>tmp) {
				printf("%d\t %s\t %d\t %.2f\n",students[i].id, students[i].name, students[i].age,students[i].adverageMarks);
			}
		}
	} else {
		printf("Command Not Recorgnized\n");
	}
}

// procedue to analyse grade
void analyse() {
	int a=0,b=0,c=0,d=0,f=0;
	if(size<=0) {
		printf("No Student Record Was Found\n");
	} else {
		printf("Students\tGrade\n");
		for(int i=0; i<size; i++) {
			if(students[i].adverageMarks>=18) {
				printf("%s\t   %.2f(A)\n",students[i].name,students[i].adverageMarks);
				a++;
			} else if(students[i].adverageMarks>=17 && students[i].adverageMarks<18) {
				printf("%s\t   %.2f(B)\n",students[i].name,students[i].adverageMarks);
				b++;
			} else if(students[i].adverageMarks>=12 && students[i].adverageMarks<17) {
				printf("%s\t   %.2f(c)\n",students[i].name,students[i].adverageMarks);
				c++;
			} else if(students[i].adverageMarks>= 10 && students[i].adverageMarks<12) {
				printf("%s\t   %.2f(D)\n",students[i].name,students[i].adverageMarks);
				d++;
			} else if(students[i].adverageMarks<9) {
				printf("%s\t   %.2f(F)\n",students[i].name,students[i].adverageMarks);
				f++;
			}
		}
// displaying analyses based on the grades scored by students(overall)
		printf("\n");
		printf("--- Overall Statistics ---\n");
		printf("A = %d Student\n",a);
		printf("B = %d Student\n",b);
		printf("C = %d Student\n",c);
		printf("D = %d Student\n",d);
		printf("F = %d Student\n",f);
	}
}

// procedue to update students
void updateStudent() {
	int new_id,total;
	printf("Enter Student ID Update: ");
	scanf("%d",&new_id);
	for(int i=0; i<size; i++) {
		if(students[i].id == new_id) {
			printf("Enter New Name: ");
			scanf("%s",&students[i].name);
			printf("Enter New Age: ");
			scanf("%d",&students[i].age);
			printf("Enter New Marks For Courses\n");
			printf("----------------------\n");
			printf("Algorithm: ");
			scanf("%d",&students[i].subjects[0]);
			printf("Maths: ");
			scanf("%d",&students[i].subjects[1]);
			printf("Web_Programing: ");
			scanf("%d",&students[i].subjects[2]);
			printf("Digital_Litracy: ");
			scanf("%d",&students[i].subjects[3]);
			printf("Computer Architecture: ");
			scanf("%d",&students[i].subjects[4]);
				for(int j=0; j<5; j++){
			total+=students[i].subjects[j];
	        	}
	       	students[i].adverageMarks = total/5;
			students[i].id=new_id;
			printf("Student Updated Successfuly\n");
			return;
		}
	}
	printf("Student Not Found In The Record");
}

//procedue to delete students
void deleteStudent() {
	int new_id;
	printf("Enter Student ID: ");
	scanf("%d",&new_id);
	for(int i=0; i<size; i++) {
		if(students[i].id == new_id) {
			for(int j=i; j<size-1; j++) {
				students[j]=students[j+1];
			}
			size--;
			printf("Student Deleted Successfully\n");
			return;
		}
	}
	printf("Student Not Found In The Record\n");
}

// my main dasboard which the user uses to interact with the program
void dasboard() {
	int option,opinion;
	do {
		printf("\nSTUDENT RECORD MANAGEMENT SYSTEM\n");
		printf("-----------------------------------\n");
		printf("1. Add a New Student\n");
		printf("2. Display All Records\n");
		printf("3. Search for a Student\n");
		printf("4. Sort Records\n");
		printf("5. Compute Average Grades\n");
		printf("6. Identify Top Performer\n");
		printf("7. Filter Students by Grades\n");
		printf("8. Update or Delete a Record\n");
		printf("9. Analyze Grades\n");
		printf("10. Exit\n");
		printf("Enter your choice: ");
		scanf("%d",&option);
// comparing the users choices and calling procedue to interact with choices 
		switch(option) {
			case 1:
				addStudent();
				break;
			case 2:
				showStudents();
				break;
			case 3:
				search();
				break;
			case 4:
				printf("Enter 1. To Sort By ID | 2. To Sort By Adverage\n");
				int choice;
				printf("Enter Option:\n");
				scanf("%d",&choice);
				if(choice ==1){
					sort_id();
					printf("Sorting In Descending Order.......");
				}else if(choice ==2){
					sort_grade();
					printf("Sorting In Descending Order.......");
				}else{
					printf("Invalid Option\n");
				}
				break;
			case 5:
				adverage();
				break;
			case 6:
				topPerformer();
				break;
			case 7:
				filter();
				break;
			case 8:
				printf("Enter 1. To Update Record | 2. To Delete Record\n");
				printf("Enter Option: ");
				scanf("%d",&opinion);
				if(opinion==1) {
					updateStudent();
				} else if(opinion ==2) {
					deleteStudent();
				} else {
					printf("Option Not Recorgnised Enter 1 To Update Or 2 To Delete Record");
				}
				break;
			case 9:
				analyse();
				break;
			case 10:
				printf("Exiting..............");
				break;
			default:
				printf("Invalid Option! Check The Option Listn And Try Again\n");
				break;
		}
	} while(option!=10);
}
// the main flow of the program
int main() {
	dasboard();
	return 0;
}
/*
this program was created using procedues with reasons as follows:
1) procedue works as functions which alloows code to be broken down into smaller secments that can be 
used throughout the entire project without having to write same code over and over
2) lastly procedues don't return result but rather prints outputs given by the developer when they 
are called explaining why the above program behaves the way it was designed.
*/