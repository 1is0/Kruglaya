using System;


namespace LabEight
{
    class Bedroom : LivingRoom, IComparable, IRoom
    {

        private readonly bool the_curtains = false;
        private string Curtains = "На окнах есть красивенькие шторы.";
        public Bedroom() : base() { }
        public Bedroom(int _furniture) : base(_furniture) { }
        public Bedroom(int _width, int _lenght, int _furniture) : base(_width, _lenght, _furniture) { }
        public Bedroom(int _width, int _lenght, int _windows, int _doors, bool _the_curtains, int _furniture) : base(_width, _lenght, _furniture)
        {
            Windows = _windows;
            Doors = _doors;
            the_curtains = _the_curtains;
        }
        public delegate void Add_Size(string m);
        public delegate void Change_of_areas(float x, float y);
        public event Change_of_areas Changed;
        public event Add_Size Added;
        public override void Inform(Print _del)
        {
            base.Inform(_del);
            if (the_curtains && Windows > 0)
            {
                _del?.Invoke(Curtains);
            }
            _del?.Invoke("");
        }

        public int CompareTo(Object obj)
        {
            if (this.Area() < ((Bedroom)obj).Area()) return -1;
            else if (this.Area() > ((Bedroom)obj).Area()) return 1;
            else return 0;
        }

        public void Add_Furniture(string m)
        {
            if (ObjInRoom == 0)
            {
                furniture = new string[1];

            }
            else
            {
                string[] temp_furniture = new string[ObjInRoom];
                for (int i = 0; i < ObjInRoom; i++)
                {
                    temp_furniture[i] = furniture[i];
                }
                furniture = new string[ObjInRoom + 1];
                for (int i = 0; i < ObjInRoom; i++)
                {
                    furniture[i] = temp_furniture[i];
                }
            }
            furniture[ObjInRoom] = m;
            ObjInRoom += 1;
            Added?.Invoke($"Вы добавили в комнату {m}.");
        }
        public void ColorOfCurtains(string Color)
        {
            if (this.Windows > 0)
            {
            Added?.Invoke($"Вы повесили на окна {Color} шторы");
            }
            else if(this.Windows<=0)
            {
                Added?.Invoke("К сожалению в комнате нет окна, чтобы повесить шторы");
            }

        }

        public void ChangeSize(int _new_width, int _new_length)
        {
            float old_area = this.Area();
            Width = _new_width;
            Lenght = _new_length;
            Added?.Invoke($"Новый размер комнаты: {_new_width} на {_new_length} ");
            Changed?.Invoke(old_area, this.Area());
        }

    }


}
