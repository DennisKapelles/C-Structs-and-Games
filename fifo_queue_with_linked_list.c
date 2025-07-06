#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *next;
};

void Insert(struct node **headRef, int newData);
int Delete(struct node **headRef);
int GetNth(struct node *head, int index);
int Count(struct node *head, int searchFor);


int main()
{
	int choice; //1 2 3 4 5
	int number_of_elements=0;
	int new_element;
	int element_position; //for question 3
	int search, position, found; // for question 4
	int deleted_element;
	
	
	struct node *a =(struct node *)malloc(sizeof(struct node)); // Αυτό θα είναι το πρώτο στοιχείο της λίστας

	struct node *headref = (struct node *)malloc(sizeof(struct node));
	
	printf("Welcome to the list\n");
	
	while(1)
	{
		printf("\nGive your choice:\n1.Insert\n2.Delete\n3.Get-Nth\n4.Count\n5.Exit\n\n");
		scanf("%d",&choice);
		
		if (choice==1)
		{
			printf("Give next element:\n");
			scanf("%d",&new_element);
			
						
			struct node *c = (struct node *)malloc(sizeof(struct node));	
			
			c->data=new_element;
				
			c->next=NULL;
			if (number_of_elements==0)
			{	
				headref=c;
			}
			else
			{
				a->next=c;
			}
			number_of_elements++;
			a=c;	
			
			c=headref;
			while(c!=NULL)
			{
				printf("-> %d ", c->data);
				c=c->next;
			}
			printf("\n");
		}
		
		
		
		
		
		
		else if (choice==2) //Delete
		{
			if(number_of_elements>0)
			{
				number_of_elements--;
				deleted_element=Delete(&headref);
				printf("Element %d is deleted\n", deleted_element);
			}
			else
			{
				printf("There are no elements in the list\n");
			}
		}
		
		
		
		
		
		
		
		else if (choice==3) //GetNth
		{
			if(number_of_elements>0)
			{
				printf("Give the element position\n");
				scanf("%d",&element_position);	
				GetNth(headref, element_position);
			}
			else
			{
				printf("There are no elements in the list\n");
			}	
		}
		
				
		else if (choice==4) //Count
		{
			if(number_of_elements>0)
			{
				printf("Give the element for searching:\n");
				scanf("%d",&search);
				
				
				found=Count(headref, search);
				printf("Element %d is in %d positions\n",search, found);
			}
			else
			{
				printf("There are no elements in the list\n");
			}
			 
		}
		else if (choice==5)
		{
			char answer;
			printf("\nAre you sure you want to exit? (Y or N)\n");
			scanf("%s",&answer);
			if(answer=='n' || answer=='N')
			{
				continue;
			}
			else if(answer=='y' || answer=='Y')
			{
				break; //Exit
			}
		}
	}
}



void Insert(struct node **headref, int new_data)
{
	struct node *c =(struct node *) malloc(sizeof(struct node));
	struct node *a = (struct node *)malloc(sizeof(struct node));
			
	int number_of_elements=0;
	a=(*headref)->next;
			
	while(a!=NULL)
	{
		number_of_elements++;
		a=a->next;
	}
	a=*headref;
				
	c->data=new_data;
	c->next=NULL;
	
	if (number_of_elements==0)
	{	
		*headref=c;
	}
	else
	{
		while(number_of_elements>0)
		{
			*headref=(*headref)->next;
					
			printf("-> %d ", (*headref)->data);
			number_of_elements--;
		}
	}

	printf("\n");
			
	*headref=a;
}




int Delete(struct node **headref)
{
	int deleted_element=(*headref)->data;
	*headref=(*headref)->next;
	
	struct node *k = (struct node *)malloc(sizeof(struct node));
	k=*headref;
	
	while(k!=NULL)
	{
		printf("-> %d ", k->data);
		k=k->next;
	}
	printf("\n");	
	return deleted_element;
}





int GetNth(struct node *head, int element_position)
{
	int position=0;
	while(head!=NULL)
	{
		if (element_position==position)
		{
			printf("In the position %d is the element %d\n\n",element_position, head->data);
			return head->data;
		}
		position++;
		head=head->next;	
	}
				
	if(head==NULL)
	{
		printf("There is not position %d in the list\n\n", element_position);
		return 0;
	}				
}



int Count(struct node *head, int search)
{
	int position=0;
	int	found=0; //δεν βρέθηκε πουθενά, αλλιώς για κάθε στοιχείο που το βρίσκει, αυξάνει κατά 1
	while(head!=NULL)
	{
		if(head->data==search)
		{	
			found++;
		}
		head=head->next;
		position++;
	}
	return found;
}
