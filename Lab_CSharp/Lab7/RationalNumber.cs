using System;


namespace LabSeven
{
    class RationalNumber : IComparable, IEquatable<RationalNumber>
    {
        public int Numerator { get; set; }
        public int Deniminator { get; set; }
 
        double number;

        

        public RationalNumber()
        {
            Numerator = 1;
            Deniminator = 1;
            number = 1;
        }
        public RationalNumber(int n, int m)
        {
            Numerator = n;
            Deniminator = m;
            number = (double)n / m;
        }
        public RationalNumber(double num)
        {
            int pow_10 = -1;
            number = num;
            if (num % 10 != 0)
            {
                while (num % 10 != 0 || Math.Abs(num) < 1)
                {
                    num *= 10;
                    pow_10++;
                }
                num /= 10;
                Numerator = (int)num;
                Deniminator = (int)Math.Pow(10, pow_10);
            }
            else
            {
                Numerator = (int)num;
                Deniminator = 1;

            }
        }

        public static RationalNumber operator +(RationalNumber x, RationalNumber y)
        {
            RationalNumber answer = new RationalNumber();
            answer.Numerator = x.Numerator * y.Deniminator + y.Numerator * x.Deniminator;
            answer.Deniminator = x.Deniminator * y.Deniminator;
            answer.number = x.number + y.number;

            return answer;
        }

        public static RationalNumber operator -(RationalNumber x, RationalNumber y)
        {
            RationalNumber answer = new RationalNumber();
            answer.Numerator = x.Numerator * y.Deniminator - y.Numerator * x.Deniminator;
            answer.Deniminator = x.Deniminator * y.Deniminator;
            answer.number = x.number - y.number;

            return answer;
        }

        public static RationalNumber operator *(RationalNumber x, RationalNumber y)
        {
            RationalNumber answer = new RationalNumber();
            answer.Numerator = x.Numerator * y.Numerator;
            answer.Deniminator = x.Deniminator * y.Deniminator;
            answer.number = x.number * y.number;

            return answer;
        }

        public static RationalNumber operator /(RationalNumber x, RationalNumber y)
        {
            RationalNumber answer = new RationalNumber();
            answer.Numerator = x.Numerator * y.Deniminator;
            answer.Deniminator = y.Numerator * x.Deniminator;
            answer.number = x.number / y.number;

            return answer;
        }
        public static RationalNumber operator %(RationalNumber x, RationalNumber y)
        {
            if (x < y)
            {
                return x;
            }
            else
            {
                double remainder = x.number - ((int)(x.number / y.number)) * x.number;
                RationalNumber answer = new RationalNumber(remainder);
                return answer;
            }
        }
        public static RationalNumber operator ++(RationalNumber x)
        {
            x.Numerator += x.Deniminator;
            x.number++;
            return x;
        }
        public static RationalNumber operator --(RationalNumber x)
        {
            x.Numerator -= x.Deniminator;
            x.number--;
            return x;
        }
        public static bool operator >(RationalNumber x, RationalNumber y) => x.number > y.number;
        public static bool operator >=(RationalNumber x, RationalNumber y) => x.number >= y.number;
        public static bool operator <(RationalNumber x, RationalNumber y) => x.number < y.number;
        public static bool operator <=(RationalNumber x, RationalNumber y) => x.number <= y.number;
        public static bool operator !=(RationalNumber x, RationalNumber y) => !x.Equals(y);
        public static bool operator ==(RationalNumber x, RationalNumber y) => x.Equals(y);

        public string  Number() =>$"{number}";
        public string Fraction() => $"{Numerator}/{Deniminator}";
        public override string ToString()
        {
            return $"Rational Number: " + Number() + "nRational number as fraction:" + Fraction();
        }

        public override bool Equals(object other)
        {
            if (other is RationalNumber)
            {
                return base.Equals((RationalNumber)other);
            }
            return false;
        }
        public bool Equals(RationalNumber num)
        {
            if (this.number == num.number) return true;
            else return false;
        }
        public override int GetHashCode()
        {
            return this.ToString().GetHashCode();
        }
        int IComparable.CompareTo(object obj)
        {
            if (this.number > ((RationalNumber)obj).number) return 1;
            else if (this.number < ((RationalNumber)obj).number) return -1;
            else return 0;
        }

        public static implicit operator double(RationalNumber x) => x.number;
        public static explicit operator int(RationalNumber x) => (int)x.number;
        public static explicit operator RationalNumber(int x)
        {
            RationalNumber result = new RationalNumber(x);
            return result;
        }

    }
}
