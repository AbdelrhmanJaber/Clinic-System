#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include"standard_types.h"
#include"clinic.h"

void AddPatientData(patient*head,patient*link)
{
	u8 flag;
	printf("Enter the id: ");
    scanf("%d",&link->id);
	fflush(stdin);
	flag=Search(head,link->id);
	if(flag==1)
		printf("this ID is already exist\n");
	else
	{
	   printf("Enter your name: ");
	   gets(link->name);
	   fflush(stdin);
	   printf("Enter your age: ");
	   scanf("%d",&link->age);
	   fflush(stdin);
	   printf("Enter your gender: ");
	   gets(link->gender);
	}
}

void EditPatientData(patient*link)
{
	    printf("Enter the id: ");
        scanf("%d",&link->id);
	    fflush(stdin);
		printf("Enter your name: ");
	    gets(link->name);
	    fflush(stdin);
	    printf("Enter your age: ");
	    scanf("%d",&link->age);
	    fflush(stdin);
	    printf("Enter your gender: ");
	    gets(link->gender);
}

u8 Search(patient*head,u32 id)
{
    patient* temp=head;
	u8 flag=0;
	if(temp==NULL)
		flag=0;
	
	while(temp!=NULL)
	{
		if(temp->id==id)
		{
			flag=1;//id is exist
	    }
		temp=temp->next;//go to the next node to check
	}
	
	return flag;	
}


patient* SearchNode(patient*head,u32 id)
{
    patient* temp=head;
	u8 flag=0;
	if(temp==NULL){
		printf("The system is empty\n");
	return temp;}
	
	else
	{
	  while(temp!=NULL)
	  {
		  if(temp->id==id)
		  {
			  flag=1;//id is exist
			  return temp;
	      }
		  temp=temp->next;//go to the next node to check
	}
	
	if (flag==0)
	{
		printf("the ID you entered doesn't exist in the system\n");
		temp=NULL;
		return temp;
	}
 }	
}


patient* AddNewPatient(patient*head)
{
	patient* link=(patient*)malloc(sizeof(patient));
	if(head==NULL) //list is empty
	{
		AddPatientData(head,link); //function of data entry
		link->next=NULL; //first and last node
		head=link;  //head points to first node
		return head;
	}
	patient*temp=head;
	while(temp->next!=NULL)
	{
		temp=temp->next;
	}
	//temp points at the last node exists
	AddPatientData(head,link);
	link->next=NULL;
	temp->next=link; //now temp points to the last node we added rightnow
	return head;
}

patient* EditPatientRecord(patient*head,u32 id)
{
	u8 flag=0;
	patient* link=head;
	if(link==NULL)
	{
		printf("the system is empty\n");
	    return link;
	}
	if(link->id==id)
	{
		flag=1;
		EditPatientData(link);
		return head;
	}
	link=link->next;
	while(link!=NULL)
	{
		if(link->id==id)
		{
			flag=1;
			EditPatientData(link);
			return head;
		}
		link=link->next;
	}
	if(flag==0)
	{
		printf("the ID you entered doesn't exist in the system\n");
		return head;
	}
}


patient* ReserveSlot(patient* head,u32 id,u8*ptr)
{
	patient* link=head;
	link=SearchNode(head,id);
	if(link==NULL)
	    return link;
	else{
	u8 slot=0;
	
		if (ptr[1]>=1)
		printf("");
		else
			printf("1- available slot to reserve from 2:00pm to 2:30pm\n");
		
		if (ptr[2]>=1)
		printf("");
		else
			printf("2- available slot to reserve from 2:30pm to 3:00pm\n");
		
		if (ptr[3]>=1)
		printf("");
		else
			printf("3- available slot to reserve from 3:00pm to 3:30pm\n");
		
		if (ptr[4]>=1)
		printf("");
		else
			printf("4- available slot to reserve from 4:00pm to 4:30pm\n");
		
		if (ptr[5]>=1)
		printf("");
		else
			printf("5- available slot to reserve from 4:30pm to 5:00pm\n");
		
	while(1)
	 {
		if((ptr[1]>=1)&&(ptr[2]>=1)&&(ptr[3]>=1)&&(ptr[4]>=1)&&(ptr[5]>=1))
		{
			printf("Sorry! All slots are reserved\n");
			break;
		}
		else
		{
	      printf("Enter the number of slot to reverse: ");
	      scanf("%d",&link->slot);
	      if((link->slot)>5)
		      printf("Wrong Entry please enter from 1 to 5\n");
	      else if((link->slot)==ptr[1]||(link->slot)==ptr[2]||(link->slot)==ptr[3]||(link->slot)==ptr[4]||
	      (link->slot)==ptr[5])
	      {
		      printf("this slot is already taken please enter another number\n");
	      }
	      else 
	      {
	         slot=link->slot;
	         ptr[slot]=slot;
	         printf("the reservation done sucssesfully\n\n");
	         return head;
	         break;
	      }
	    }
	 }
   }
}

patient* CancelReservation(patient*head,u32 id,u8 *ptr)
{
	patient*temp=head;
	u8 flag=0;
	if(temp==NULL){
		printf("The system is empty\n");
	return head;}
	else
	{
	while(temp!=NULL)
	  {
		  if(temp->id==id)
		  {
			  flag=1;
			  ptr[(temp->slot)]=0;
			  return head;
	      }
		  temp=temp->next;//go to the next node to check
	  }
	}
	if(flag==0)
	{
		printf("the ID you entered doesn't exist in the system\n");
		return head;
	}
}


void ViewPatientRecord(patient* head,u32 id)
{
	u8 flag=0;
	patient*link=head;
	if(link==NULL)
	{
		printf("the system is empty\n");
	    return ;
	}
	if(link->id==id)
	{
		flag=1;
		printf("the name of patient %s\n",link->name);
		printf("the age of patient %d years\n",link->age);
		printf("the gender of patient %s\n",link->gender);
		return;
	}
	link=link->next;
	while(link!=NULL)
	{
		if(link->id==id)
	  {
		  flag=1;
		  printf("the name of patient %s\n",link->name);
		  printf("the age of patient %d years\n",link->age);
		  printf("the gender of patient %s\n",link->gender);
		  return;
	  }
	  link=link->next;
	}
	if(flag==0)
		printf("the ID you entered doesn't exist in the system\n");
}

void ViewReserveations (patient* head)
{
	patient* temp=head;
	if(temp==NULL)
	{
		printf("The system is empty\n");
		return;
	}
	else
	{
		while(temp!=NULL)
		{
			printf("the ID of the patient: %d\n",temp->id);
			if((temp->slot)==1)
				printf("the patient reservation from 2:00pm to 2:30pm\n\n");
			
			else if((temp->slot)==2)
				printf("the patient reservation from 2:30pm to 3:00pm\n\n");
			
			else if((temp->slot)==3)
				printf("the patient reservation from 3:00pm to 3:30pm\n\n");
			
			else if((temp->slot)==4)
				printf("the patient reservation from 4:00pm to 4:30pm\n\n");
			
			else if((temp->slot)==5)
				printf("the patient reservation from 4:30pm to 5:00pm\n\n");
			else
			{
				printf("the patient didn't reserve a slot today\n");
			}
			temp=temp->next;
		}
	}
}