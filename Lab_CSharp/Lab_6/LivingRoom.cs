using System;


namespace Lab_Six
{
    abstract class LivingRoom : Room
    {
        protected string[] furniture;
        protected int ObjInRoom = 0;
        public LivingRoom() : base() { }
        public LivingRoom(int _furniture)
        {
            furniture = new string[_furniture];

        }

        public string this[int _furniture]
        {
            set
            {
                furniture[_furniture] = value;
                ObjInRoom++;

            }
            get
            {
                return furniture[_furniture];
            }
        }
        public LivingRoom(int _width, int _lenght, int _furniture) : base(_width, _lenght)
        {

            furniture = new string[_furniture];


        }


        public override void Inform()
        {
            Console.Write($"Высота комнаты: {Lenght} , ширина комнаты: {Width} , окон в комнате: {Windows}, дверей в комнате: {Doors}.");
            int m = 0;
            if (ObjInRoom != 0)
            {

                Console.Write(" Мебель в комнате :");
                while (m < ObjInRoom)
                {
                    Console.Write($" {furniture[m]} ");
                    m++;
                }
            }
            Area();
        }
    }
}
