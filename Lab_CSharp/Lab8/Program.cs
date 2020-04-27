using System;


namespace LabEight
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
        

        static void Main(string[] args)
        {

            var Room =CreateRoom();
            Room.Inform((m)=> Console.WriteLine(m));
            Room.Adding += (n) => Console.WriteLine(n);
            Room.Added += delegate (string m)
            {
                Console.WriteLine(m);
            };
            Room.Changed += (x, y) => Console.WriteLine($"Размер комнаты изменился на {Math.Abs(x - y)} единиц квадратных");
            Room.ColorOfCurtains("красные");
            Room.Add(5,6);
            Room.ColorOfCurtains("красные");
            Room.ChangeSize(10, 5);
            Room.Add_Furniture("кресло");
            Room.Inform(delegate(string m)
            {
                Console.WriteLine(m);
            });


            Console.ReadLine();

        }
    }
}
