using System;
using System.Windows.Forms;

namespace BMI_Calculator
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }

        private void label1_Click(object sender, EventArgs e)
        {

        }

        private void label3_Click(object sender, EventArgs e)
        {

        }

        private void textBox2_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void button1_Click(object sender, EventArgs e)
        {
            int height = 0; 
            int weight = 0; 
            double bmi = 0; 

            height = Convert.ToInt32(textBox1.Text); 
            weight = Convert.ToInt32(textBox2.Text);            
            bmi = weight / ((height / 100.0) * (height / 100.0)); 
            bmi = Math.Round(bmi, 2); 

            textBox3.Text = bmi.ToString(); 
            if (bmi < 18.5) this.textBox3.Text = "體重過輕, BMI = " + bmi; 
            else if (bmi < 24) this.textBox3.Text = "健康體位, BMI = " + bmi; 
            else if (bmi < 27) this.textBox3.Text = "過重, BMI = " + bmi;
            else if (bmi < 30) this.textBox3.Text = "輕度肥胖, BMI = " + bmi; 
            else if (bmi<35) this.textBox3.Text = "中度肥胖, BMI = " + bmi; 
            else this.textBox3.Text="重度肥胖";
        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
