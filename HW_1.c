#include <stdio.h>
#include <stdlib.h>
#include <string.h>






//Creating the struct
struct Student
{
 char name[50];
 char gender;
 struct Student * next;
};






struct Student * insertNode (char *name, char gender, struct Student * list)
{
 struct Student *s;
 //Allocate memory for node (malloc operation)
 s = malloc (sizeof (struct Student));
 if (s == NULL)
 {
 printf ("Memory allocation failed.");
 return list;
 }
 strcpy(s->name, name);
 s->gender = gender;
 s->next = list; //list is the start of the list
 list = s;

 return list;
}





//Sorting function
struct Student * sortList (struct Student *list)
{
	
    int swapped;//checks if it's swapped
    //pointers for controlling swapping
    struct Student *ptr1; 
    struct Student *lptr = NULL; 
    char tempn[2];//temp for names
    char tempg;//temp for genders

    
  //sorting the names by reverse alphabetical order
        do
    { 
        swapped = 0; 
        ptr1 = list; 
  
        while (ptr1->next != lptr) //while end of the linked list
        {  
	
			
            if (strcmp(ptr1->name , ptr1->next->name)<0) //swap names in reverse alphabetical order and also swap the genders  
            {  
                
                 strcpy(tempn , ptr1->name); 
				 tempg=ptr1->gender;
                 strcpy(ptr1->name , ptr1->next->name);
				ptr1->gender=ptr1->next->gender;
                 strcpy(ptr1->next->name , tempn); 
                 ptr1->next->gender=tempg;
				  swapped = 1; 
            } 
            ptr1 = ptr1->next; 
            
        } 
        
        
    } 
    while (swapped); 
        
		 
    
   //sort the reverse alphabetical ordered list by gender
    lptr = NULL; 
    do
    { 
        swapped = 0; 
        ptr1 = list; 
  
        while (ptr1->next != lptr) //until the end of the reverse alhabetical ordered linked list
        {  
	
			
            if (ptr1->gender> ptr1->next->gender) //swap the females to the front and males to the end of the linked list also swap their genders too
            {  
                
                 strcpy(tempn , ptr1->name); 
				 tempg=ptr1->gender;
                 strcpy(ptr1->name , ptr1->next->name);
				ptr1->gender=ptr1->next->gender;
                 strcpy(ptr1->next->name , tempn); 
                 ptr1->next->gender=tempg;
             
				  swapped = 1; 
            } 
            ptr1 = ptr1->next; 
            
        } 
        
		 
    } 
    while (swapped); 
    
    
    
    // sort females ,in the reverse alphabetical linked list , by alphabetical order
     do
    { 
        swapped = 0; 
        ptr1 = list; 
  
        while (ptr1->next->gender != 'M') //starting from females ,until reaching males (this way only females will ve in alphabetical order)
        {  
	
			
            if (strcmp(ptr1->name , ptr1->next->name)>0) ////swap names in alphabetical order and also swap the genders 
            {  
                
                 strcpy(tempn , ptr1->name); 
				 tempg=ptr1->gender;
                 strcpy(ptr1->name , ptr1->next->name);
				ptr1->gender=ptr1->next->gender;
                 strcpy(ptr1->next->name , tempn); 
                 ptr1->next->gender=tempg;
             
				  swapped = 1; 
            } 
            ptr1 = ptr1->next; 
            
        } 
         
    }  
    while (swapped); 
    
    return list;

    
  	}
  


//Printing function
void printList (struct Student * list)
{
 while (list != NULL)
 {
 printf ("%s\t%c\n", list->name, list->gender);
 list = list->next;
 }
}






int main ()
{
 //Creating an Initial Node Variable
 struct Student * head=NULL;
 //Call to functions
    head = insertNode("Cenk", 'M', head);
    head = insertNode("Ceyda", 'F', head);
    head = insertNode("Esra", 'F', head);
    head = insertNode("Okan", 'M', head);
    head = insertNode("Tugce", 'F', head);
    head = insertNode("Mehmet", 'M', head);
    head= insertNode("Ayse", 'F', head);
    head = insertNode("Merve", 'F', head);
    head = insertNode("Sedat", 'M', head);
    head = insertNode("Ahmet", 'M', head);
 //call to sorting function
 head = sortList(head);
 printList(head);
}



/*
REFERENCES
1-https://tutorialspoint.dev/algorithm/sorting-algorithms/c-program-bubble-sort-linked-list  for bubble sort algorithm
2-https://www.youtube.com/watch?v=A28lN86quGY&t=351s   for swapping and sorting by alphabetical order




*/
