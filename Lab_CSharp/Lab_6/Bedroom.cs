using System;


namespace Lab_Six
{
    class Bedroom : LivingRoom, IComparable, IRoom
    {

        private readonly bool the_curtains = false;
        private string Curtains = "На окнах есть красивенькие занавески.";
        public Bedroom() : base() { }
        public Bedroom(int _furniture) : base(_furniture) { }
        public Bedroom(int _width, int _lenght, int _furniture) : base(_width, _lenght, _furniture) { }
        public Bedroom(int _width, int _lenght, int _windows, int _doors, bool _the_curtains, int _furniture) : base(_width, _lenght, _furniture)
        {
            Windows = _windows;
            Doors = _doors;
            the_curtains = _the_curtains;
        }
        
        public override void Inform()
        {
            base.Inform();
            if (the_curtains && Windows > 0)
            {
                Console.Write(Curtains);
            }
            Console.WriteLine();
        }

        public int CompareTo(Object obj)
        {
            if (this.Area() < ((Bedroom)obj).Area()) return -1;
            else if (this.Area() > ((Bedroom)obj).Area()) return 1;
            else  return 0;
        }
         

        public void ColorOfCurtains(string Color)
        {
            Curtains = $"На окнах есть {Color} занавески";
        }
        
        public void ChangeSize(int _new_width, int _new_length)
        {
            Width = _new_width;
            Lenght = _new_length;
        }

        
    }
}
