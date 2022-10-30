import java.util.*;
public class doublyll
{
  class Node
  {
    int info;
    Node prev,next;
    public Node(int item)
    {
    	this.info=item;
    }
  }
  static Node head=null,tail=null,p;
  void InsertFirst(int val)
  {
	p=new Node(val);
  	p.next=head;
	if(head==null)
	   head=tail=p;
	else
        {
    	  head.prev=p;
    	  head=p;
        }
  }
    
  void InsertAfter(int item,int item1)
  {
	Node curr=head;
	while(curr!=null && curr.info!=item1)
	{
		curr=curr.next;
	}
	if(curr==null)
	   System.out.printf("No such element or node");
	else
        {
    	  p=new Node(item);
    	  p.prev=curr;
    	  p.next=curr.next;
    	  if(curr==tail)
    	     tail=p;
    	  else
             curr.next.prev=p;
          curr.next=p;
        }
  }

 void InsertBefore(int item,int item1)
 {
	Node curr=head;
	while(curr!=null && curr.info!=item1)
	     curr=curr.next;
	 if(curr==null)
	    System.out.printf("No such node or element");
	 else
         {
     	  p=new Node(item);
     	  p.prev=curr.prev;
     	  p.next=curr;
     	  if(curr==head)
     	     head=p;
     	  else
             curr.prev.next=p;
          curr.prev=p;
         } 
 }	

void TraverseRight(Node head)
{
	Node curr=head;
	while(curr!=null)
	{
		System.out.printf("%d",curr.info);
		curr=curr.next;
		if(curr!=null)
		  System.out.printf("-->");
        }
} 

void TraverseLeft(Node tail)
{
	Node ptr=tail;
	while(ptr!=null)
	{

		System.out.printf("%d",ptr.info);
		ptr=ptr.prev;
		if(ptr!=null)
		   System.out.printf("<--");
	}
}	

void Delete(int item)
{
  Node curr=head;
  while(curr!=null && curr.info != item)
	curr = curr.next;
  if(curr == null)
	System.out.printf("No such element or node");
	else 
	{
		if(curr == head)
		   head = curr.next;
		else
		   curr.prev.next=curr.next;
		if(curr == tail)
		   tail = curr.prev;
		else
		   curr.next.prev=curr.prev;
        }
}		
 public static void main(String[] args) 
{
  Scanner sc=new Scanner(System.in);
  doublyll d=new doublyll();
  int ch,po,it;
  do
  {
       System.out.printf("\nDoubly LinkedList Operations are:\n");
       System.out.printf("\n1.Insfirst\n2.InsAfter\n3.InsBefore\n4.TraverseRight\n5.TraverseLeft\n6.Delete\n7.Exit\n");
       System.out.printf("\nEnter your choice:\n");
       ch=sc.nextInt();
       switch(ch)
       { 

         case 1:System.out.printf("Enter the value to be inserted first:");
                po=sc.nextInt();
                d.InsertFirst(po);                        
                break;

         case 2:System.out.printf("Enter item after which an element is to be inserted:");
                it=sc.nextInt();
                System.out.printf("Value to be inserted:");
                po=sc.nextInt();
                d.InsertAfter(po,it);                   
                break;

         case 3:System.out.printf("Enter item before which an element is to be inserted:");
                it=sc.nextInt();
                System.out.printf("Value to be inserted:");
                po=sc.nextInt();
                d.InsertBefore(po,it);                   
                break;

         case 4:d.TraverseRight(head);
                break;

         case 5:d.TraverseLeft(tail);
                 break;

         case 6:System.out.printf("Enter the value to be deleted:");
                po=sc.nextInt();
                d.Delete(po);
                break;

         case 7:break;

         default:System.out.printf("Invalid choice");
       }
    }while(ch!=7);
    sc.close(); 
  }
}
