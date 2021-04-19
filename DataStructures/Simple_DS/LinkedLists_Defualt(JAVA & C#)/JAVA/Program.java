package Liists;
import java.util.*;

public class Program
{
	
	public static void main(String[] args)
	{
		//list تعریف 
		ArrayList<Persons> list1 = new ArrayList<Persons>();
		//تعریف شخص ها
		Persons p1 = new Persons("Ali1", "Mehdipour1", "1");
		Persons p2 = new Persons("Ali2", "Mehdipour2", "2");
		Persons p3 = new Persons("Ali3", "Mehdipour3", "3");
		Persons p4 = new Persons("Ali4", "Mehdipour4", "4");
		Persons p5 = new Persons("Ali5", "Mehdipour5", "5");
		//Listاضافه کردن شخص ها به 
		list1.add(p1);
		ListPrinter(list1, "Adding p1 person");
		list1.add(p2);
		ListPrinter(list1, "Adding p2 person");
		list1.add(p3);
		ListPrinter(list1, "Adding p3 person");
		//حذف شخص دلخواه از لیست
		list1.remove(p2);
		ListPrinter(list1, "Removing p2 person");
		//index افزودن شخص دلخواه با دادن 
		list1.add(1, p4);
		ListPrinter(list1, "inserting p4 person by means of index in the middle of list");
		//-----------------------------------------------------------------------------------------
		//persons از جنس linked-list ساخت یک     
		LinkedList<Persons> linkedlist1 = new LinkedList<Persons>();
		//ها node اضافه کردن اشخاص دلخواه با استفاده از مفهوم 
		linkedlist1.addFirst(p1); //Very FAST(No Need to find node)
		LinkedListPrinter(linkedlist1, "Granting p1 person FIRST as the HEADBOX of linked-list");
		linkedlist1.add(linkedlist1.indexOf(p1), p2); //SLOWER(Need to find nodes)
		LinkedListPrinter(linkedlist1, "Add p2 person before p1 as the HEADBOX");
		linkedlist1.add(linkedlist1.indexOf(p2), p3); //SLOWER(Need to find nodes)
		LinkedListPrinter(linkedlist1, "Add p3 person ");
		linkedlist1.add(linkedlist1.indexOf(p1), p4); //SLOWER(Need to find nodes)
		LinkedListPrinter(linkedlist1, "Add p4 person ");
		linkedlist1.addLast(p5); //Very FAST(No Need to find node)
		LinkedListPrinter(linkedlist1, "Add p5 person as the LASTBOX of The Linked-List");
		//  حذف کردن اشخاص دلخواه با استفاده از مقدار مقدار و هویت آنها
		linkedlist1.remove(p1);
		LinkedListPrinter(linkedlist1, "REMOVING p1 person by means of its value");
		//ها node حذف کردن اشخاص دلخواه با استفاده از مفهوم 
		linkedlist1.remove(linkedlist1.indexOf(p2));
		LinkedListPrinter(linkedlist1, "REMOVING p2 person by means of its <<NODE>>");

		//------------------------------------------------------------------------------------------

	}
	private static void ListPrinter(ArrayList<Persons> list, String Description)
	{
		System.out.println(Description + "\n");
		System.out.println(String.format("The list Quantity is:%1$s\n", list.size()));
		for (Persons p : list)
		{
			System.out.println(String.format("Name: %1$s\tFamily: %2$s\tID: %3$s",p.getPrpName(),p.getPrpFamily(),p.getPrpID()));
		}
		System.out.println("=============================================================================\n");
	}

	private static void LinkedListPrinter(LinkedList<Persons> list, String Description)
	{
		System.out.println(Description + "\n");
		System.out.println(String.format("The Linked-list Quantity is:%1$s\n", list.size()));
		for (Persons p : list)
		{
			System.out.println(String.format("Name: %1$s\tFamily: %2$s\tID: %3$s", p.getPrpName(), p.getPrpFamily(), p.getPrpID()));
		}
		System.out.println("********************************************************************************\n");
	}
}

