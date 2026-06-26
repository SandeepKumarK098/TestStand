using System;
using System.Threading;
using System.Collections;
using System.ComponentModel;
using System.Windows.Forms;

namespace Utilities
{
	/// <summary>
	/// Summary description for TimedDialog.
	/// </summary>
	public class TimedDialog : System.Windows.Forms.Form
	{
		private System.Windows.Forms.Label MessageTextLabel;
		private System.Windows.Forms.Button YesButton;
		private System.Windows.Forms.Button NoButton;
		private System.Windows.Forms.Timer mTimer;
		new private System.Windows.Forms.Button CancelButton;
		private string title;

		int counter = 0;
		private IContainer components;

		public TimedDialog(string title, string message, int timeToWait, string yesButtonText, string noButtonText)
		{
			//
			// Required for Windows Form Designer support
			//
			InitializeComponent();

			MessageTextLabel.Text = message;
			this.counter = timeToWait;
			this.title = title;
			if (this.title.Length == 0)
				this.title = this.Text;


			YesButton.Text = yesButtonText;
			NoButton.Text = noButtonText;
		}

		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		protected override void Dispose( bool disposing )
		{
			if( disposing )
			{
				if(components != null)
				{
					components.Dispose();
				}
			}
			base.Dispose( disposing );
		}

		#region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		private void InitializeComponent()
		{
			this.components = new System.ComponentModel.Container();
			this.MessageTextLabel = new System.Windows.Forms.Label();
			this.YesButton = new System.Windows.Forms.Button();
			this.NoButton = new System.Windows.Forms.Button();
			this.CancelButton = new System.Windows.Forms.Button();
			this.mTimer = new System.Windows.Forms.Timer(this.components);
			this.SuspendLayout();
			// 
			// MessageTextLabel
			// 
			this.MessageTextLabel.Location = new System.Drawing.Point(16, 16);
			this.MessageTextLabel.Name = "MessageTextLabel";
			this.MessageTextLabel.Size = new System.Drawing.Size(368, 96);
			this.MessageTextLabel.TabIndex = 0;
			this.MessageTextLabel.Text = "Message Text";
			// 
			// YesButton
			// 
			this.YesButton.DialogResult = System.Windows.Forms.DialogResult.Yes;
			this.YesButton.Location = new System.Drawing.Point(56, 120);
			this.YesButton.Name = "YesButton";
			this.YesButton.Size = new System.Drawing.Size(80, 23);
			this.YesButton.TabIndex = 1;
			this.YesButton.Text = "Yes";
			// 
			// NoButton
			// 
			this.NoButton.DialogResult = System.Windows.Forms.DialogResult.No;
			this.NoButton.Location = new System.Drawing.Point(168, 120);
			this.NoButton.Name = "NoButton";
			this.NoButton.Size = new System.Drawing.Size(80, 23);
			this.NoButton.TabIndex = 2;
			this.NoButton.Text = "No";
			// 
			// CancelButton
			// 
			this.CancelButton.DialogResult = System.Windows.Forms.DialogResult.Cancel;
			this.CancelButton.Location = new System.Drawing.Point(272, 120);
			this.CancelButton.Name = "CancelButton";
			this.CancelButton.Size = new System.Drawing.Size(80, 23);
			this.CancelButton.TabIndex = 3;
			this.CancelButton.Text = "Cancel";
			// 
			// mTimer
			// 
			this.mTimer.Enabled = true;
			this.mTimer.Interval = 1000;
			this.mTimer.Tick += new System.EventHandler(this.mTimer_Tick);
			// 
			// TimedDialog
			// 
			this.AcceptButton = this.NoButton;
			this.AutoScaleBaseSize = new System.Drawing.Size(5, 13);
			this.ClientSize = new System.Drawing.Size(408, 158);
			this.ControlBox = false;
			this.Controls.Add(this.NoButton);
			this.Controls.Add(this.YesButton);
			this.Controls.Add(this.MessageTextLabel);
			this.Controls.Add(this.CancelButton);
			this.MaximizeBox = false;
			this.MinimizeBox = false;
			this.Name = "TimedDialog";
			this.StartPosition = System.Windows.Forms.FormStartPosition.CenterScreen;
			this.Text = "LabVIEW Process(es) Running";
			this.Load += new System.EventHandler(this.TimedDialog_Load);
			this.ResumeLayout(false);

		}
		#endregion

		private void TimedDialog_Load(object sender, System.EventArgs e)
		{
			this.YesButton.Select();
		}

		private void mTimer_Tick(object sender, EventArgs e)
		{
			this.Text = this.title + " (Timeout in " + this.counter.ToString() + " sec.)";
			this.counter--;

			if (this.counter < 0)
				this.DialogResult = DialogResult.Yes;
		}
	}
}
