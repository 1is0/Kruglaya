using System;


namespace Lab_Six
{
    class Program
    {
        public static int CheckInt()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a))
            {
                Console.WriteLine("Ошибка, введите данные еще раз.");
            }
            return a;
        }
        public static bool CheckBool()
        {
            bool a = false;
            while (!bool.TryParse(Console.ReadLine(), out a))
            {

                Console.WriteLine("Ошибка, введите данные еще раз.");
            }
            return a;
        }
        public static string Check()
        {
            string a;
            a = Console.ReadLine();
            while (a.Length > 30)
            {
                Console.WriteLine("Пожалуйста введите более корректное и короткое название предмета");
                a = Console.ReadLine();
            }
            return a;
        }
        public static Bedroom CreateRoom()
        {

            Console.WriteLine("Введите данные о комнате ");
            Console.WriteLine("Ширина комнаты: ");
            int Width = CheckInt();
            Console.WriteLine("Длина комнаты: ");
            int Lenght = CheckInt();
            Console.WriteLine("Количество окон в комнате: ");
            int Windows = CheckInt();
            Console.WriteLine("Количество дверей в комнате: ");
            int Doors = CheckInt();
            bool The_curtains = false;
            if (Windows > 0)
            {
                Console.WriteLine("Будут ли занавески в комнате? true / false");
                The_curtains = CheckBool();


            }
            Console.WriteLine("Сколько будет предметов в комнате?");
            int Amount = CheckInt();
            Bedroom Room = new Bedroom(Width, Lenght, Windows, Doors, The_curtains, Amount);
            if (Amount > 0)
            {
                Console.WriteLine("Какая мебель будет в комнате? ");
                for (int i = 0; i < Amount; i++)
                {
                    Room[i] = Check();
                }
            }
            Console.Clear();
            return Room;
        }
        public static void List_Room(Bedroom[] List)
        {
            for (int i = 0; i < List.Length; i++)
            {
                List[i] = CreateRoom();
            }
            for (int i = 0; i < List.Length; i++)
            {
                Console.Write(i + 1 + ")"); List[i].Inform();
            }

        }

        static void Main(string[] args)
        {

            Console.WriteLine("Сколько комнат вы хотите создать?");
            int Amount_Of_New_Room = CheckInt();
            Bedroom[] List = new Bedroom[Amount_Of_New_Room];
            List_Room(List);

            if (List.Length >= 2)
            {
                Console.WriteLine("Какие две комнаты сравнить?");
                int One = CheckInt() - 1;
                int Two = CheckInt() - 1;
                if (List[One].CompareTo(List[Two]) == 0)
                {
                    Console.WriteLine("Комнаты имеют одинаковый размер");
                }
                else if (List[One].CompareTo(List[Two]) < 0)
                {
                    Console.WriteLine("Размер первой комнаты меньше второй");
                }
                else Console.WriteLine("Размер первой комнаты больше второй");
            }
            Console.ReadLine();
            Console.Clear();
            var Room = CreateRoom();
            Room.Inform();
            Room.ColorOfCurtains("красные");
            Room.ChangeSize(10, 5);
            Room.Inform();


            Console.ReadLine();

        }
    }
}
