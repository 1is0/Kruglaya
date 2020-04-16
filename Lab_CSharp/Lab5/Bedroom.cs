using System;


namespace Lab_Five
{
    class Bedroom : LivingRoom
    {

        private readonly bool the_curtains = false;
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
                Console.Write("На окнах есть красивенькие занавески.");
            }
            Console.WriteLine();
        }



    }
}
