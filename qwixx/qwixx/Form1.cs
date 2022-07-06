using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace qwixx
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
            datasloading();
        }

        private void checkBox1_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            //Declarate variables
            int greyDiceOne, greyDiceTwo, redDice, yellowDice, greenDice, blueDice;
            //Dice
            Random rnd = new Random();
            greyDiceOne = rnd.Next(0, 12);
            greyDiceTwo = rnd.Next(0, 12);
            redDice = rnd.Next(0, 12);
            yellowDice = rnd.Next(0, 12);
            greenDice = rnd.Next(0, 12);
            blueDice = rnd.Next(0, 12);
            //to text
            greyDicePtOne.Text = greyDiceOne.ToString();
            greyDicePtTwo.Text = greyDiceTwo.ToString();
            redDicePt.Text = redDice.ToString();
            yellowDicePt.Text = yellowDice.ToString();
            greenDicePt.Text = greenDice.ToString();
            blueDicePt.Text = blueDice.ToString();
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox6_TextChanged(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void panel3_Paint(object sender, PaintEventArgs e)
        {

        }

        public void datasloading()
        {
            int hiba, x, redX, yellowX, greenX, blueX, greyDiceOne, greyDiceTwo, redDice, yellowDice, greenDice, blueDice = 0;

            
          
        }

        private void checkBox9_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox10_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox37_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox32_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox31_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void checkBox5_CheckedChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click_1(object sender, EventArgs e)
        {

  
        }

        private void szamol_Click(object sender, EventArgs e)
        {
            int redCheckedBoxes = redPanel.Controls.OfType<CheckBox>().Count(c => c.Checked);
            int yellowCheckedBoxes = yellowPanel.Controls.OfType<CheckBox>().Count(c => c.Checked);
            int greenCheckedBoxes = greenPanel.Controls.OfType<CheckBox>().Count(c => c.Checked);
            int blueCheckedBoxes = bluePanel.Controls.OfType<CheckBox>().Count(c => c.Checked);
            int hibaCheckedBoxes = hibaPanel.Controls.OfType<CheckBox>().Count(c => c.Checked);
            int redpoints = 0;
            int yellowpoints = 0;
            int greenpoints = 0;
            int bluepoints = 0;
            int hiba = hibaCheckedBoxes * 5;
            for(int i = 1; i <= redCheckedBoxes; i++)
            {
                redpoints += i;
            }
            for (int i = 1; i <= yellowCheckedBoxes; i++)
            {
                yellowpoints += i;
            }
            for (int i = 1; i <= greenCheckedBoxes; i++)
            {
                greenpoints += i;
            }
            for (int i = 1; i <= blueCheckedBoxes; i++)
            {
                bluepoints += i;
            }

            int eredmeny = (redpoints + yellowpoints + greenpoints + bluepoints) - hiba;


            redPoints.Text = redpoints.ToString();
            yellowPoint.Text = yellowpoints.ToString();
            greenPoint.Text = greenpoints.ToString();
            bluePoint.Text = bluepoints.ToString();
            redEredmenyTb.Text = redpoints.ToString();
            yellowEredmenyTb.Text = yellowpoints.ToString();
            greenEredmenyTb.Text = greenpoints.ToString();
            blueEredmenyTb.Text = bluepoints.ToString();
            hibaEredmenyTb.Text = hiba.ToString();
            osszEredmenyTb.Text = eredmeny.ToString();
            redpoints = 0;
            yellowpoints = 0;
            greenpoints = 0;
            bluepoints = 0;

        }
    }
}
