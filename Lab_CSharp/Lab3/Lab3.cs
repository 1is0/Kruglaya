using System;


namespace LabThreeCS
{
    class Room
    {
        private float width;
        private float hight;

        public int Windows { get; set; }
        public int Doors { get; set; }

        protected string[] furniture;
        public static int ObjInRoom = 0; // Статический элемент класса

        public float Width               // Свойства
        {

            set
            {
                if (value < 0)
                {
                    width = -1 * value;
                }
                else
                {
                    width = value;
                }
            }
            get
            {
                return width;
            }
        }
        public float Hight
        {

            set
            {
                if (value < 0)
                {
                    hight = -1 * value;
                }
                else
                {
                    hight = value;
                }
            }
            get
            {
                return hight;
            }
        }


        public Room() { Windows = 0; Doors = 1; }       // Конструкторы




        public Room(int m)
        {
            furniture = new string[m];
            ObjInRoom += m;
        }

        public string this[int m]                      // Индексатор
        {
            set
            {
                furniture[m] = value;
            }
            get
            {
                return furniture[m];
            }
        }

        public void Inform()                           // Методы   
        {
            Console.WriteLine($"Высота комнаты: {hight} , ширина комнаты: {width} , окон в комнате: {Windows}, дверей в комнате: {Doors} .");
        }
        public void Area()
        {
            float area = width * hight;
            Console.WriteLine($"Площадь комнаты : {area} единиц квадратных ");
        }

        public void Add(int n)                         // Перегрузка методов
        {
            Windows += n;
        }

        public void Add(int n, int m)
        {
            Windows += n;
            Doors += m;
        }
    }


    class Lab3
    {
        static void Main(string[] args)
        {
            Room room1 = new Room(3) //пример
            {
                Width = 7,
                Hight = 8
            };

            room1.Inform();
            room1.Area();

            room1.Add(3);

            room1.Inform();

            room1.Add(1, 2);

            room1.Inform();

            room1[0] = "стол";
            room1[1] = "кресло";
            room1[2] = "вешалка";

            Console.WriteLine($"Количество мебели в комнате: {Room.ObjInRoom}. \nВ комнате есть {room1[0]}, {room1[1]} и {room1[2]} ");




            Console.ReadKey();


        }
    }
}
