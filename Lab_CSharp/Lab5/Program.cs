using System;


namespace Lab_Five
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
            int Amount_Of_New_Room = 0;
            Bedroom One = new Bedroom();
            Bedroom Two = new Bedroom(5, 6, 3);
            var Three = CreateRoom();
            One.Inform();
            Two.Inform();
            Three.Inform();

            Console.WriteLine("Сколько еще комнат вы хотите создать?");
            Amount_Of_New_Room = CheckInt();
            Bedroom[] List = new Bedroom[Amount_Of_New_Room];
            List_Room(List);
            Console.WriteLine("Всего создано комнат: {0}", Bedroom.number_of_room);
            Console.ReadLine();
        }
    }
}
