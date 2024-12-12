using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;
using System.IO;
using System.Security;

namespace Lottery
{
    public partial class Form1 : Form
    {
        public Form1()
        {
            InitializeComponent();
        }
        //private Dictionary<int, Name> map = new Dictionary<int, Name>();
        private List<Lot> lotterybox = new List<Lot>();
        private int total;
        private int lots;
        private int draws;
        private void button1_Click(object sender, EventArgs e)
        {
            if (openFileDialog1.ShowDialog() == DialogResult.OK)
            {
                try
                {
                    var reader = new StreamReader(File.OpenRead(openFileDialog1.FileName),Encoding.Default);
                    textBox1.Clear();
                    int i = 0;
                    while (!reader.EndOfStream)
                    {
                        string line = reader.ReadLine();
                        textBox1.Text += line + Environment.NewLine;
                        string[] ReadLine_Array = line.Split(',');
                        lotterybox.Add(new Lot { fullname = ReadLine_Array[0], ID = Int32.Parse(ReadLine_Array[1]) });
                        i++;
                    }
                    reader.Close();
                    total = i;
                    textBox2.Text = total.ToString();
                    lots = i;
                    textBox3.Text = lots.ToString();                    //StreamReader SR = new StreamReader(@"files\enrollment1.csv", System.Text.Encoding.Default);
                }
                catch (SecurityException ex)
                {
                    MessageBox.Show($"Security error.\n\nError message: {ex.Message}\n\n" +
                    $"Details:\n\n{ex.StackTrace}");
                }
            }

        }

        private void button2_Click(object sender, EventArgs e)
        {
            if (string.IsNullOrWhiteSpace(textBox4.Text))
            {
                MessageBox.Show("請輸入抽獎人數。", "輸入錯誤", MessageBoxButtons.OK, MessageBoxIcon.Warning);
                return;
            }
            draws = Int32.Parse(textBox4.Text);
            Random rnd = new Random();  //產生亂數初始值
            textBox1.Clear();
            draws = (draws <= lotterybox.Count) ? draws : lotterybox.Count;
            try
            {
                //Pass the filepath and filename to the StreamWriter Constructor
                StreamWriter sw = new StreamWriter("lotterylog.txt",true);
                sw.WriteLine(DateTime.Now.ToString("ddd dd MMM, yyyy")+"  設定抽獎人數："+draws.ToString());
                for (int i=0;i<draws;i++)
                {
                    int key = rnd.Next(0, lotterybox.Count-1);
                    textBox1.Text += "              " + lotterybox[key].fullname + "        " + lotterybox[key].ID + Environment.NewLine;
                    sw.WriteLine(lotterybox[key].fullname + "," + lotterybox[key].ID);
                    lotterybox.RemoveAt(key);
                }
                lots -= draws;
                textBox3.Text = lots.ToString();
                sw.Close();
            }
            catch (SecurityException ex)
            {
                MessageBox.Show($"Security error.\n\nError message: {ex.Message}\n\n" +
                $"Details:\n\n{ex.StackTrace}");
            }
        }

        private void button3_Click(object sender, EventArgs e)
        {
            textBox1.Visible = !textBox1.Visible;
        }

        private void textBox4_TextChanged(object sender, EventArgs e)
        {

        }

        private void textBox3_TextChanged(object sender, EventArgs e)
        {

        }

        private void Form1_Load(object sender, EventArgs e)
        {

        }
    }
}
