#include<stdio.h>
#include<stdlib.h>
#include"standard_types.h"
#include"clinic.h"
#define ADMIN 1
#define USER 2

enum 
{
	ADD_NEW_PATIENT_RECORD=1,
	EDIT_PATIENT_RECORD,
	RESERVE_A_SLOT,
	CANCEL_RESERVATION
}admin;

enum
{
	VIEW_PATIENT_RECORD=1,
	VIEW_TODAY_RESERVATION
}user;

u8 arr[6]={0,0,0,0,0,0};
void main(void)
{
	patient*head=NULL;
	u32 option,password,id,mode;
	u8 counter=0;
	while(1)
	{
		if(counter>=2)
			counter=0;
		printf("\n================================\n");
		printf("1- Admin mode\n2- User mode\n");
		printf("3- Exit from the system\n");
		printf("Enter the mode: ");
		scanf("%d",&mode);
		printf("\n================================\n");
		
		switch(mode)
		{
			case ADMIN:
			printf("__________________Welcom in Admin Mode__________________\n");
			printf("Enter the password: ");
			scanf("%d",&password);
			while((counter<2)&&(password!=1234))
			{	
				printf("you entered wrong password please try again\n");
				printf("Enter the password: ");
				scanf("%d",&password);
				counter++;
			}
			if(counter==2&&password!=1234)
			{
				printf("you entered the password three times wrong there is no more trials\n\n");
				break;
			}
	     	else
			{
				printf("\n================================\n");
				printf("1- Add new patient record\n2- Edit patient record\n");
				printf("3- Reserve a slot with the doctor\n");
				printf("4- Cancel reservation\nEnter the option: ");
				scanf("%d",&option);
				printf("\n================================\n");
				switch(option)
				{
					case ADD_NEW_PATIENT_RECORD:
					head=AddNewPatient(head);
					break;
					
					case EDIT_PATIENT_RECORD:
					printf("Enter the ID to edit the data: ");
					scanf("%d",&id);
					head=EditPatientRecord(head,id);
					break;
					
					case RESERVE_A_SLOT:
					printf("Enter the ID to reserve a slot: ");
					scanf("%d",&id);
					ReserveSlot(head,id,&arr[0]);
					break;
					
					case CANCEL_RESERVATION:
					printf("Enter the ID to cancel reservation: ");
					scanf("%d",&id);
					head=CancelReservation(head,id,&arr[0]);
					break;
				}
			}
			break;
			case USER:
			printf("__________________Welcom in User Mode__________________\n");
			printf("\n================================\n");
			printf("1- View patient record \n");
			printf("2- View today's reservations \n");
			printf("Enter the option: ");
			scanf("%d",&option);
			printf("\n================================\n");
			
			switch(option)
			{
				case VIEW_PATIENT_RECORD:
				printf("Enter the ID to view the patient data: ");
			    scanf("%d",&id);
				ViewPatientRecord(head,id);
				break;
				case VIEW_TODAY_RESERVATION:
				ViewReserveations(head);
				break;
			}
			break;
		}
		if(mode==3)
			break;
	}
}