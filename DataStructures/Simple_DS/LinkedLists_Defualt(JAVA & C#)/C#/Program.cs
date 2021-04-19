using System;
using System.Collections;
using System.Collections.Generic;

namespace ListsDataStructure
{
    class Program
    {
        
        static void Main(string[] args)
        {
            //list تعریف 
            List<Persons> list1 = new List<Persons>();
            //تعریف شخص ها
            Persons p1 = new Persons("Ali1", "Mehdipour1", "1");
            Persons p2 = new Persons("Ali2", "Mehdipour2", "2");
            Persons p3 = new Persons("Ali3", "Mehdipour3", "3");
            Persons p4 = new Persons("Ali4", "Mehdipour4", "4");
            Persons p5 = new Persons("Ali5", "Mehdipour5", "5");

            //Listاضافه کردن شخص ها به 
            list1.Add(p1);
            ListPrinter(list1,"Adding p1 person");
            list1.Add(p2);
            ListPrinter(list1,"Adding p2 person");
            list1.Add(p3);
            ListPrinter(list1,"Adding p3 person");
            //حذف شخص دلخواه از لیست
            list1.Remove(p2);
            ListPrinter(list1, "Removing p2 person");
            //index افزودن شخص دلخواه با دادن 
            list1.Insert(1, p4);
            ListPrinter(list1, "inserting p4 person by means of index in the middle of list");
            //-----------------------------------------------------------------------------------------
            //persons از جنس linked-list ساخت یک     
            LinkedList<Persons> linkedlist1 = new LinkedList<Persons>();
            //ها node اضافه کردن اشخاص دلخواه با استفاده از مفهوم 
            linkedlist1.AddFirst(p1);//Very FAST(No Need to find node)
            LinkedListPrinter(linkedlist1,"Granting p1 person FIRST as the HEADBOX of linked-list");
            linkedlist1.AddBefore(linkedlist1.Find(p1), p2);         //SLOWER(Need to find nodes)
            LinkedListPrinter(linkedlist1, "Add p2 person before p1 as the HEADBOX");
            linkedlist1.AddAfter(linkedlist1.Find(p2), p3);          //SLOWER(Need to find nodes)
            LinkedListPrinter(linkedlist1,"Add p3 person after p2 person in the middle of linked-list");
            linkedlist1.AddBefore(linkedlist1.Find(p1), (p4));       //SLOWER(Need to find nodes)
            LinkedListPrinter(linkedlist1,"Add p4 person before p1 as third box of the linked-list");
            linkedlist1.AddLast(p5);                                 //Very FAST(No Need to find node)
            LinkedListPrinter(linkedlist1,"Add p5 person as the LASTBOX of The Linked-List");
            //  حذف کردن اشخاص دلخواه با استفاده از مقدار مقدار و هویت آنها
            linkedlist1.Remove(p1);
            LinkedListPrinter(linkedlist1,"REMOVING p1 person by means of its value");
            //ها node حذف کردن اشخاص دلخواه با استفاده از مفهوم 
            linkedlist1.Remove(linkedlist1.Find(p2));
            LinkedListPrinter(linkedlist1, "REMOVING p2 person by means of its <<NODE>>");

            //------------------------------------------------------------------------------------------

            Console.ReadKey();
        }
        static void ListPrinter(List<Persons> list,string Description) {
            Console.WriteLine(Description + "\n");
            Console.WriteLine($"The list Quantity is:{list.Count}\n");
            foreach(Persons p  in list)
            {
                Console.WriteLine(string.Format("Name: {0}\tFamily: {1}\tID: {2}",p.prpName,p.prpFamily,p.prpID));
            }
            Console.WriteLine("=============================================================================\n");
        }

        static void LinkedListPrinter(LinkedList<Persons> list, string Description)
        {
            Console.WriteLine(Description+"\n");
            Console.WriteLine($"The Linked-list Quantity is:{list.Count}\n");
            foreach (Persons p in list)
            {
                Console.WriteLine(string.Format("Name: {0}\tFamily: {1}\tID: {2}", p.prpName, p.prpFamily, p.prpID));
            }
            Console.WriteLine("********************************************************************************\n");
        }
    }
    //کلاس مربوط به اشخاص
    class Persons
    {
        //کلاس اشخاص برای گرفتن ویژگی های هر فردconstructor
        public Persons(string name, string family, string id)
        {
            prpName = name;
            prpFamily = family;
            prpID = id;
        }
        //ست کردن ویژگی های افراد
        public string prpName { get; set; }
        public string prpFamily { get; set; }
        public string prpID { get; set; }

    }
}
