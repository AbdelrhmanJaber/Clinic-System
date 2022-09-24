#ifndef CLINIC_H
#define CLINIC_H
typedef struct myStruct
{
	u32 id;
	u32 age;
	u32 slot;
	u8 name[30];
	u8 gender[7];
	struct myStruct* next;
}patient;
void AddPatientData(patient*head,patient*link);
void EditPatientData(patient*link);
u8 Search(patient*head,u32 id);
patient* AddNewPatient(patient*head);
patient* EditPatientRecord(patient*head,u32 id);
void ViewPatientRecord(patient* head,u32 id);
patient* ReserveSlot(patient* head,u32 id,u8*ptr);
patient* CancelReservation(patient*head,u32 id,u8* ptr);
void ViewReserveations (patient* head);
#endif