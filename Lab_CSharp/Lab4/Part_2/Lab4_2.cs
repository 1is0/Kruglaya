using System;
using System.Runtime.InteropServices;

namespace LabFourPartTwo
{

    public class LibImport
    {


        [DllImport("MathLib.dll", CallingConvention = CallingConvention.StdCall, ExactSpelling = false, EntryPoint = "SumLib")]
        public static extern int SumLib(int a, int b);
        public int Sum(int a, int b)
        {
            return SumLib(a, b);
        }

        [DllImport("MathLib.dll", CallingConvention = CallingConvention.StdCall, ExactSpelling = false, EntryPoint = "DifferenceLib")]
        public static extern int DifferenceLib(int a, int b);
        public int Difference(int a, int b)
        {
            return DifferenceLib(a, b);
        }

        [DllImport("MathLib.dll", CallingConvention = CallingConvention.StdCall, ExactSpelling = false, EntryPoint = "CompositionLib")]
        public static extern int CompositionLib(int a, int b);
        public int Composition(int a, int b)
        {
            return CompositionLib(a, b);
        }

        [DllImport("MathLib.dll", CallingConvention = CallingConvention.StdCall, ExactSpelling = false, EntryPoint = "DivisionLib")]
        public static extern float DivisionLib(int a, int b);
        public float Division(int a, int b)
        {
            return DivisionLib(a, b);
        }

        [DllImport("MathLib.dll", CallingConvention = CallingConvention.StdCall, ExactSpelling = false, EntryPoint = "CompareLib")]
        public static extern int CompareLib(int a, int b);
        public int Compare(int a, int b)
        {
            return CompareLib(a, b);
        }

    }


    class Lab4_2
    {
        public static bool Check(out int number)
        {
            if (!int.TryParse(Console.ReadLine(), out number))
            {
                Console.WriteLine("Ошибка. Неправильно введенный символ. Нажмите Enter, чтобы продолжить");
                Console.ReadLine();
                return true;
            }
            else
            {
                return false;
            }

        }
        static void Main(string[] args)
        {
            int a, b;
            bool t = true;
            LibImport import = new LibImport();
            while (t)
            {

                Console.Write("Введите первое число:");
               if(Check(out a))
                {
                    continue;
                }
                Console.Write("Введите второе число:");
                if (Check(out b))
                {
                    continue;
                }
                Console.WriteLine("Сумма двух чисел  равна: {0}", import.Sum(a, b));
                Console.WriteLine("Разность двух чисел равна: {0}", import.Difference(a, b));
                Console.WriteLine("Произведение двух чисел равно: {0}", import.Composition(a, b));
                Console.WriteLine("Частное двух чисел равно: {0}", import.Division(a, b));
                import.Compare(a, b);

                t = false;
                Console.ReadLine();


            }
        }
    }
}
