using System;
using System.Drawing;
using System.Threading;
using System.Windows.Forms;

public class NTTU_ISMS_OJ : Form
{
    private static Form win;
    private static Form win_boot;
    private static string ver = "Beta";
    private static string screensize = "1920x1080";

    public NTTU_ISMS_OJ()
    {
        // Main window setup
        win = new Form();
        win.Size = new Size(1920, 1080);
        win.FormBorderStyle = FormBorderStyle.None;
        win.Text = $"NTTU ISMS::OJ - Version {ver}";
        win.Icon = new Icon("Extension_modules/NTTU_LOGO.ico");
        win.Hide();

        // Bootup window setup
        win_boot = new Form();
        win_boot.Size = new Size(640, 360);
        win_boot.StartPosition = FormStartPosition.Manual;
        win_boot.Location = new Point(640, 360);
        win_boot.FormBorderStyle = FormBorderStyle.None;
        win_boot.Text = "NTTU ISMS::OJ";

        PictureBox pic = new PictureBox();
        pic.Image = Image.FromFile("Extension_modules/bootup.png");
        pic.SizeMode = PictureBoxSizeMode.StretchImage;
        pic.Dock = DockStyle.Fill;
        win_boot.Controls.Add(pic);

        // Start the destroy thread
        Thread t = new Thread(new ThreadStart(Destroy));
        t.Start();
    }

    private static void Destroy()
    {
        Thread.Sleep(2000);
        win_boot.Invoke(new Action(() => {
            win_boot.Close();
            win.Show();
        }));
    }

    [STAThread]
    public static void Main()
    {
        Application.EnableVisualStyles();
        Application.SetCompatibleTextRenderingDefault(false);
        Application.Run(new NTTU_ISMS_OJ());
    }
}