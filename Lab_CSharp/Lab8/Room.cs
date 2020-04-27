using System;


namespace LabEight
{
    abstract class Room
    {
        private float width;
        private float lenght;

        public delegate void Add_(string n);
        public delegate void Print(string n);
        public event Add_ Adding;
        public int Windows { get; set; }
        public int Doors { get; set; }




        public static int number_of_room = 0;

        public float Width
        {

            set
            {
                if (value < 0)
                {
                    width = -1 * value;
                }
                else if (value > 1000)
                {
                    width = 1000;
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
        public float Lenght
        {

            set
            {
                if (value < 0)
                {
                    lenght = -1 * value;
                }
                else if (value > 1000)
                {
                    lenght = 1000;

                }
                else
                {
                    lenght = value;
                }
            }
            get
            {
                return lenght;
            }
        }


        public Room() { Width = 1; Lenght = 1; Windows = 0; Doors = 1; number_of_room++; }
        public Room(int n, int m)
        {
            Width = n;
            Lenght = m;
            number_of_room++;
        }


        public float Area()
        {
            return width * lenght;
        }

        public virtual void Inform(Print _del)
        {
            _del?.Invoke($"Высота комнаты: {Lenght} , ширина комнаты: {Width} , окон в комнате: {Windows}, дверей в комнате: {Doors} .\nПлощадь комнаты : {Area()} единиц квадратных ");


        }


        public void Add(int n)
        {
            Adding?.Invoke($"Вы добавляете в комнату {n} окон.");
            Windows += n;
        }

        public void Add(int n, int m)
        {
            Adding?.Invoke($"Вы добавляете в комнату {n} окон и {m} дверей.");
            Windows += n;
            Doors += m;
        }

    }
}
