using System;
using System.Drawing;
using System.Windows.Forms;

namespace LabFourPartOne
{
    public partial class Form1 : Form
    {
    
        bool IsClicked = false;
        Color CurrentColor = Color.Black;
        Point CurrentPoint;
        Point PrevPoint;
        Graphics G;

        public Form1()
        {
            InitializeComponent();
            
            G = panel2.CreateGraphics();
           
        }

        private void Form1_Load(object sender, EventArgs e)
        {
            this.FormBorderStyle = FormBorderStyle.None;
            this.AllowTransparency = true;
            this.BackColor = Color.AliceBlue;
            this.TransparencyKey = this.BackColor;
           


        }

        private void button1_Click(object sender, EventArgs e)
        {
            Close();
        }

      

        

        private void button2_Click(object sender, EventArgs e)
        {
            DialogResult D = colorDialog1.ShowDialog();
            if (D == DialogResult.OK)
            {
                CurrentColor = colorDialog1.Color;
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            panel2.Refresh();
        }

        private void panel2_MouseDown(object sender, MouseEventArgs e)
        {
            IsClicked = true;
            CurrentPoint = e.Location;
        }

        private void panel2_MouseMove(object sender, MouseEventArgs e)
        {
            if (IsClicked)
            {
                PrevPoint = CurrentPoint;
                CurrentPoint = e.Location;
                For_paint();

            }
        }

        private void panel2_MouseUp(object sender, MouseEventArgs e)
        {
            IsClicked = false;
        }

        private void For_paint()
        {
            Pen mypen = new Pen(CurrentColor,5);
            G.DrawLine(mypen, PrevPoint, CurrentPoint);

        }

        private void panel2_Paint(object sender, PaintEventArgs e)
        {

        }
    }
}
