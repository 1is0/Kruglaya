using System;


namespace LabSeven
{
    class Program
    {

        public static int CheckInt()
        {
            int a;
            while (!int.TryParse(Console.ReadLine(), out a))
            {
                Console.WriteLine("Ошибка, введите данные еще раз. \n");
            }
            return a;
        }
        public static RationalNumber Number()
        {
            Console.WriteLine("Введите рациональное число: ");
            double x;
            while (!double.TryParse(Console.ReadLine(), out x))
            {
                Console.WriteLine("Вы ввели некорректное число, попробуйте еще раз.\n");
            }
            return new RationalNumber(x);
        }
        public static RationalNumber Fraction()
        {

            string number;
            string integer = "";
            string natural = "";
            Console.WriteLine("Введите число: ");
            number = Console.ReadLine();

            char[] array = number.ToCharArray();
            for (int i = 0, index = number.IndexOf('/'); i != index; i++)
            {
                integer += array[i];
            }
            for (int i = number.IndexOf('/') + 1; i < number.Length; i++)
            {
                natural += array[i];
            }

            int.TryParse(integer, out int n);
            int.TryParse(natural, out int m);

            return new RationalNumber(n, m);

        }
        public static RationalNumber Create()
        {
            int choice;
            Console.WriteLine("В каком виде будете вводить число: 0 - Дробь / 1 - С плавающей точкой \n");
            while (!int.TryParse(Console.ReadLine(), out choice) || choice < 0 || choice > 1)
            {
                Console.WriteLine("Ошибка, введите данные еще раз. \n");
            }
            if (choice == 1)
            {
                return Number();
            }
            else
            {
                return Fraction();
            }

        }
        static void Main(string[] args)
        {
            Console.WriteLine("Введите первое число");
            RationalNumber num1 = Create();

            Console.WriteLine("Введите второе число");
            RationalNumber num2 = Create();

            Console.Clear();
            Console.WriteLine("Перое число:\n" + num1);
            Console.WriteLine("ВТорое число:\n" + num2);
            Console.WriteLine($"Сравнение чисел: {num1.Fraction()} > {num2.Fraction()} = " + (num1 > num2));
            Console.WriteLine($"{num1.Number()} > {num2.Number()} = " + (num1 > num2) + "\n");
            Console.WriteLine($"{num1.Fraction()} < {num2.Fraction()} = " + (num1 < num2));
            Console.WriteLine($"{num1.Number()} < {num2.Number()} = " + (num1 < num2) + "\n");
            Console.WriteLine($"{num1.Fraction()} == {num2.Fraction()} = " + (num1 == num2));
            Console.WriteLine($"{num1.Number()} == {num2.Number()} = " + (num1 == num2) + "\n");
            Console.WriteLine($"{num1.Fraction()} != {num2.Fraction()} = " + (num1 != num2));
            Console.WriteLine($"{num1.Number()} != {num2.Number()} = " + (num1 != num2) + "\n");
            Console.WriteLine($"Сложение: {num1.Fraction()} + {num2.Fraction()} = " + (num1 + num2).Fraction());
            Console.WriteLine($"   {num1.Number()} + {num2.Number()} = " + (num1 + num2).Number() + "\n");
            Console.WriteLine($"Вычитание: {num1.Fraction()} - {num2.Fraction()} = " + (num1 - num2).Fraction());
            Console.WriteLine($"   {num1.Number()} - {num2.Number()} = " + (num1 - num2).Number() + "\n");
            Console.WriteLine($"Умножение: {num1.Fraction()} * {num2.Fraction()} = " + (num1 * num2).Fraction());
            Console.WriteLine($"   {num1.Number()} * {num2.Number()} = " + (num1 * num2).Number() + "\n");
            Console.WriteLine($"Остаток от деления: {num1.Fraction()} % {num2.Fraction()} = " + (num1 % num2).Fraction());
            Console.WriteLine($"   {num1.Number()} % {num2.Number()} = " + (num1 % num2).Number() + "\n");
            if (num2 != 0)
            {
                Console.WriteLine($"Деление: {num1.Fraction()} / {num2.Fraction()} = " + (num1 / num2).Fraction());
                Console.WriteLine($"   {num1.Number()} / {num2.Number()} = " + (num1 / num2).Number() + "\n");
            }

            Console.ReadLine();
        }
    }
}
