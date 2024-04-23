using System;
using System.Windows.Forms;

namespace SendCommandOverSerial
{
    partial class MainUI
    {
        /// <summary>
        /// Required designer variable.
        /// </summary>
        private System.ComponentModel.IContainer components = null;

        /// <summary>
        /// Clean up any resources being used.
        /// </summary>
        /// <param name="disposing">true if managed resources should be disposed; otherwise, false.</param>
        protected override void Dispose(bool disposing)
        {
            if (disposing && (components != null))
            {
                components.Dispose();
            }
            base.Dispose(disposing);
        }

        #region Windows Form Designer generated code

        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        private void InitializeComponent()
        {
            this.components = new System.ComponentModel.Container();
            this.cmbSerialPorts = new System.Windows.Forms.ComboBox();
            this.label1 = new System.Windows.Forms.Label();
            this.btnForward = new System.Windows.Forms.Button();
            this.btnLeft = new System.Windows.Forms.Button();
            this.btnRight = new System.Windows.Forms.Button();
            this.btnBackward = new System.Windows.Forms.Button();
            this.btnBuzzer = new System.Windows.Forms.Button();
            this.radRemoteControl = new System.Windows.Forms.RadioButton();
            this.radObstacleAvoidance = new System.Windows.Forms.RadioButton();
            this.radOpenLab = new System.Windows.Forms.RadioButton();
            this.groupBox1 = new System.Windows.Forms.GroupBox();
            this.btnStopBalancing = new System.Windows.Forms.RadioButton();
            this.btnStop = new System.Windows.Forms.Button();
            this.chkConnected = new System.Windows.Forms.CheckBox();
            this.btnKpSpeedUp = new System.Windows.Forms.Button();
            this.btnKpSpeedDown = new System.Windows.Forms.Button();
            this.btnKpAngleUp = new System.Windows.Forms.Button();
            this.btnKpAngleDown = new System.Windows.Forms.Button();
            this.txtSerialResult = new System.Windows.Forms.TextBox();
            this._serialPort = new System.IO.Ports.SerialPort(this.components);
            this.btnKiSpeedUp = new System.Windows.Forms.Button();
            this.btnKiSpeedDown = new System.Windows.Forms.Button();
            this.btnTiltBackward = new System.Windows.Forms.Button();
            this.btnTiltForward = new System.Windows.Forms.Button();
            this.label3 = new System.Windows.Forms.Label();
            this.label2 = new System.Windows.Forms.Label();
            this.label4 = new System.Windows.Forms.Label();
            this.btnKiAngleUp = new System.Windows.Forms.Button();
            this.btnKiAngleDown = new System.Windows.Forms.Button();
            this.label5 = new System.Windows.Forms.Label();
            this.groupBox1.SuspendLayout();
            this.SuspendLayout();
            // 
            // cmbSerialPorts
            // 
            this.cmbSerialPorts.FormattingEnabled = true;
            this.cmbSerialPorts.Location = new System.Drawing.Point(37, 307);
            this.cmbSerialPorts.Name = "cmbSerialPorts";
            this.cmbSerialPorts.Size = new System.Drawing.Size(206, 21);
            this.cmbSerialPorts.TabIndex = 2;
            // 
            // label1
            // 
            this.label1.AutoSize = true;
            this.label1.Location = new System.Drawing.Point(34, 291);
            this.label1.Name = "label1";
            this.label1.Size = new System.Drawing.Size(55, 13);
            this.label1.TabIndex = 4;
            this.label1.Tag = "Ser";
            this.label1.Text = "Serial Port";
            // 
            // btnForward
            // 
            this.btnForward.Location = new System.Drawing.Point(121, 62);
            this.btnForward.Name = "btnForward";
            this.btnForward.Size = new System.Drawing.Size(75, 23);
            this.btnForward.TabIndex = 9;
            this.btnForward.Text = "Forward";
            this.btnForward.UseVisualStyleBackColor = true;
            this.btnForward.Click += new System.EventHandler(this.btnForward_Click);
            // 
            // btnLeft
            // 
            this.btnLeft.Location = new System.Drawing.Point(37, 104);
            this.btnLeft.Name = "btnLeft";
            this.btnLeft.Size = new System.Drawing.Size(75, 23);
            this.btnLeft.TabIndex = 10;
            this.btnLeft.Text = "Left";
            this.btnLeft.UseVisualStyleBackColor = true;
            this.btnLeft.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnLeft_MouseDown);
            this.btnLeft.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnLeft_MouseUp);
            // 
            // btnRight
            // 
            this.btnRight.Location = new System.Drawing.Point(215, 104);
            this.btnRight.Name = "btnRight";
            this.btnRight.Size = new System.Drawing.Size(75, 23);
            this.btnRight.TabIndex = 11;
            this.btnRight.Text = "Right";
            this.btnRight.UseVisualStyleBackColor = true;
            this.btnRight.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnRight_MouseDown);
            this.btnRight.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnRight_MouseUp);
            // 
            // btnBackward
            // 
            this.btnBackward.Location = new System.Drawing.Point(121, 150);
            this.btnBackward.Name = "btnBackward";
            this.btnBackward.Size = new System.Drawing.Size(75, 23);
            this.btnBackward.TabIndex = 12;
            this.btnBackward.Text = "Backward";
            this.btnBackward.UseVisualStyleBackColor = true;
            this.btnBackward.Click += new System.EventHandler(this.btnBackward_Click);
            // 
            // btnBuzzer
            // 
            this.btnBuzzer.Location = new System.Drawing.Point(376, 127);
            this.btnBuzzer.Name = "btnBuzzer";
            this.btnBuzzer.Size = new System.Drawing.Size(75, 23);
            this.btnBuzzer.TabIndex = 13;
            this.btnBuzzer.Text = "Buzzer";
            this.btnBuzzer.UseVisualStyleBackColor = true;
            this.btnBuzzer.MouseDown += new System.Windows.Forms.MouseEventHandler(this.btnBuzzer_MouseDown);
            this.btnBuzzer.MouseUp += new System.Windows.Forms.MouseEventHandler(this.btnBuzzer_MouseUp);
            // 
            // radRemoteControl
            // 
            this.radRemoteControl.AutoSize = true;
            this.radRemoteControl.Location = new System.Drawing.Point(28, 41);
            this.radRemoteControl.Name = "radRemoteControl";
            this.radRemoteControl.Size = new System.Drawing.Size(98, 17);
            this.radRemoteControl.TabIndex = 14;
            this.radRemoteControl.TabStop = true;
            this.radRemoteControl.Text = "Remote Control";
            this.radRemoteControl.UseVisualStyleBackColor = true;
            this.radRemoteControl.CheckedChanged += new System.EventHandler(this.radRemoteControl_CheckedChanged);
            // 
            // radObstacleAvoidance
            // 
            this.radObstacleAvoidance.AutoSize = true;
            this.radObstacleAvoidance.Location = new System.Drawing.Point(28, 64);
            this.radObstacleAvoidance.Name = "radObstacleAvoidance";
            this.radObstacleAvoidance.Size = new System.Drawing.Size(121, 17);
            this.radObstacleAvoidance.TabIndex = 15;
            this.radObstacleAvoidance.TabStop = true;
            this.radObstacleAvoidance.Text = "Obstacle Avoidance";
            this.radObstacleAvoidance.UseVisualStyleBackColor = true;
            this.radObstacleAvoidance.CheckedChanged += new System.EventHandler(this.radObstacleAvoidance_CheckedChanged);
            // 
            // radOpenLab
            // 
            this.radOpenLab.AutoSize = true;
            this.radOpenLab.Location = new System.Drawing.Point(28, 87);
            this.radOpenLab.Name = "radOpenLab";
            this.radOpenLab.Size = new System.Drawing.Size(102, 17);
            this.radOpenLab.TabIndex = 16;
            this.radOpenLab.TabStop = true;
            this.radOpenLab.Text = "OpenLab Result";
            this.radOpenLab.UseVisualStyleBackColor = true;
            this.radOpenLab.CheckedChanged += new System.EventHandler(this.radOpenLab_CheckedChanged);
            // 
            // groupBox1
            // 
            this.groupBox1.Controls.Add(this.btnStopBalancing);
            this.groupBox1.Controls.Add(this.radRemoteControl);
            this.groupBox1.Controls.Add(this.radOpenLab);
            this.groupBox1.Controls.Add(this.radObstacleAvoidance);
            this.groupBox1.Location = new System.Drawing.Point(252, 272);
            this.groupBox1.Name = "groupBox1";
            this.groupBox1.Size = new System.Drawing.Size(200, 119);
            this.groupBox1.TabIndex = 17;
            this.groupBox1.TabStop = false;
            this.groupBox1.Text = "Mode";
            // 
            // btnStopBalancing
            // 
            this.btnStopBalancing.AutoSize = true;
            this.btnStopBalancing.Location = new System.Drawing.Point(28, 17);
            this.btnStopBalancing.Name = "btnStopBalancing";
            this.btnStopBalancing.Size = new System.Drawing.Size(97, 17);
            this.btnStopBalancing.TabIndex = 17;
            this.btnStopBalancing.TabStop = true;
            this.btnStopBalancing.Text = "Stop Balancing";
            this.btnStopBalancing.UseVisualStyleBackColor = true;
            this.btnStopBalancing.CheckedChanged += new System.EventHandler(this.btnStopBalancing_CheckedChanged);
            // 
            // btnStop
            // 
            this.btnStop.Location = new System.Drawing.Point(121, 104);
            this.btnStop.Name = "btnStop";
            this.btnStop.Size = new System.Drawing.Size(75, 23);
            this.btnStop.TabIndex = 18;
            this.btnStop.Text = "Stop";
            this.btnStop.UseVisualStyleBackColor = true;
            this.btnStop.Click += new System.EventHandler(this.btnStop_Click);
            // 
            // chkConnected
            // 
            this.chkConnected.AutoSize = true;
            this.chkConnected.Location = new System.Drawing.Point(36, 340);
            this.chkConnected.Name = "chkConnected";
            this.chkConnected.Size = new System.Drawing.Size(78, 17);
            this.chkConnected.TabIndex = 19;
            this.chkConnected.Text = "Connected";
            this.chkConnected.UseVisualStyleBackColor = true;
            this.chkConnected.CheckedChanged += new System.EventHandler(this.chkConnected_CheckedChanged);
            // 
            // btnKpSpeedUp
            // 
            this.btnKpSpeedUp.Location = new System.Drawing.Point(40, 207);
            this.btnKpSpeedUp.Name = "btnKpSpeedUp";
            this.btnKpSpeedUp.Size = new System.Drawing.Size(75, 23);
            this.btnKpSpeedUp.TabIndex = 20;
            this.btnKpSpeedUp.Text = "Up";
            this.btnKpSpeedUp.UseVisualStyleBackColor = true;
            this.btnKpSpeedUp.Click += new System.EventHandler(this.btnKpSpeedUp_Click);
            // 
            // btnKpSpeedDown
            // 
            this.btnKpSpeedDown.Location = new System.Drawing.Point(40, 236);
            this.btnKpSpeedDown.Name = "btnKpSpeedDown";
            this.btnKpSpeedDown.Size = new System.Drawing.Size(75, 23);
            this.btnKpSpeedDown.TabIndex = 21;
            this.btnKpSpeedDown.Text = "Down";
            this.btnKpSpeedDown.UseVisualStyleBackColor = true;
            this.btnKpSpeedDown.Click += new System.EventHandler(this.btnKpSpeedDown_Click);
            // 
            // btnKpAngleUp
            // 
            this.btnKpAngleUp.Location = new System.Drawing.Point(212, 207);
            this.btnKpAngleUp.Name = "btnKpAngleUp";
            this.btnKpAngleUp.Size = new System.Drawing.Size(75, 23);
            this.btnKpAngleUp.TabIndex = 22;
            this.btnKpAngleUp.Text = "Up";
            this.btnKpAngleUp.UseVisualStyleBackColor = true;
            this.btnKpAngleUp.Click += new System.EventHandler(this.btnKpAngleUp_Click);
            // 
            // btnKpAngleDown
            // 
            this.btnKpAngleDown.Location = new System.Drawing.Point(212, 236);
            this.btnKpAngleDown.Name = "btnKpAngleDown";
            this.btnKpAngleDown.Size = new System.Drawing.Size(75, 23);
            this.btnKpAngleDown.TabIndex = 23;
            this.btnKpAngleDown.Text = "Down";
            this.btnKpAngleDown.UseVisualStyleBackColor = true;
            this.btnKpAngleDown.Click += new System.EventHandler(this.btnKpAngleDown_Click);
            // 
            // txtSerialResult
            // 
            this.txtSerialResult.Location = new System.Drawing.Point(36, 396);
            this.txtSerialResult.Multiline = true;
            this.txtSerialResult.Name = "txtSerialResult";
            this.txtSerialResult.ScrollBars = System.Windows.Forms.ScrollBars.Vertical;
            this.txtSerialResult.Size = new System.Drawing.Size(415, 133);
            this.txtSerialResult.TabIndex = 24;
            // 
            // btnKiSpeedUp
            // 
            this.btnKiSpeedUp.Location = new System.Drawing.Point(121, 207);
            this.btnKiSpeedUp.Name = "btnKiSpeedUp";
            this.btnKiSpeedUp.Size = new System.Drawing.Size(75, 23);
            this.btnKiSpeedUp.TabIndex = 25;
            this.btnKiSpeedUp.Text = "Up";
            this.btnKiSpeedUp.UseVisualStyleBackColor = true;
            this.btnKiSpeedUp.Click += new System.EventHandler(this.btnKiSpeedUp_Click);
            // 
            // btnKiSpeedDown
            // 
            this.btnKiSpeedDown.Location = new System.Drawing.Point(121, 236);
            this.btnKiSpeedDown.Name = "btnKiSpeedDown";
            this.btnKiSpeedDown.Size = new System.Drawing.Size(75, 23);
            this.btnKiSpeedDown.TabIndex = 26;
            this.btnKiSpeedDown.Text = "Down";
            this.btnKiSpeedDown.UseVisualStyleBackColor = true;
            this.btnKiSpeedDown.Click += new System.EventHandler(this.btnKiSpeedDown_Click);
            // 
            // btnTiltBackward
            // 
            this.btnTiltBackward.Location = new System.Drawing.Point(293, 24);
            this.btnTiltBackward.Name = "btnTiltBackward";
            this.btnTiltBackward.Size = new System.Drawing.Size(84, 23);
            this.btnTiltBackward.TabIndex = 27;
            this.btnTiltBackward.Text = "Tilt backward";
            this.btnTiltBackward.UseVisualStyleBackColor = true;
            this.btnTiltBackward.Click += new System.EventHandler(this.btnTiltBackward_Click);
            // 
            // btnTiltForward
            // 
            this.btnTiltForward.Location = new System.Drawing.Point(383, 24);
            this.btnTiltForward.Name = "btnTiltForward";
            this.btnTiltForward.Size = new System.Drawing.Size(84, 23);
            this.btnTiltForward.TabIndex = 28;
            this.btnTiltForward.Text = "Tilt forward";
            this.btnTiltForward.UseVisualStyleBackColor = true;
            this.btnTiltForward.Click += new System.EventHandler(this.btnTiltForward_Click);
            // 
            // label3
            // 
            this.label3.AutoSize = true;
            this.label3.Location = new System.Drawing.Point(48, 194);
            this.label3.Name = "label3";
            this.label3.Size = new System.Drawing.Size(54, 13);
            this.label3.TabIndex = 30;
            this.label3.Text = "Kp Speed";
            // 
            // label2
            // 
            this.label2.AutoSize = true;
            this.label2.Location = new System.Drawing.Point(135, 194);
            this.label2.Name = "label2";
            this.label2.Size = new System.Drawing.Size(50, 13);
            this.label2.TabIndex = 31;
            this.label2.Text = "Ki Speed";
            // 
            // label4
            // 
            this.label4.AutoSize = true;
            this.label4.Location = new System.Drawing.Point(225, 194);
            this.label4.Name = "label4";
            this.label4.Size = new System.Drawing.Size(50, 13);
            this.label4.TabIndex = 32;
            this.label4.Text = "Kp Angle";
            // 
            // btnKiAngleUp
            // 
            this.btnKiAngleUp.Location = new System.Drawing.Point(293, 207);
            this.btnKiAngleUp.Name = "btnKiAngleUp";
            this.btnKiAngleUp.Size = new System.Drawing.Size(75, 23);
            this.btnKiAngleUp.TabIndex = 33;
            this.btnKiAngleUp.Text = "Up";
            this.btnKiAngleUp.UseVisualStyleBackColor = true;
            this.btnKiAngleUp.Click += new System.EventHandler(this.btnKiAngleUp_Click);
            // 
            // btnKiAngleDown
            // 
            this.btnKiAngleDown.Location = new System.Drawing.Point(293, 236);
            this.btnKiAngleDown.Name = "btnKiAngleDown";
            this.btnKiAngleDown.Size = new System.Drawing.Size(75, 23);
            this.btnKiAngleDown.TabIndex = 34;
            this.btnKiAngleDown.Text = "Down";
            this.btnKiAngleDown.UseVisualStyleBackColor = true;
            this.btnKiAngleDown.Click += new System.EventHandler(this.btnKiAngleDown_Click);
            // 
            // label5
            // 
            this.label5.AutoSize = true;
            this.label5.Location = new System.Drawing.Point(309, 194);
            this.label5.Name = "label5";
            this.label5.Size = new System.Drawing.Size(46, 13);
            this.label5.TabIndex = 35;
            this.label5.Text = "Ki Angle";
            // 
            // MainUI
            // 
            this.AutoScaleDimensions = new System.Drawing.SizeF(6F, 13F);
            this.AutoScaleMode = System.Windows.Forms.AutoScaleMode.Font;
            this.ClientSize = new System.Drawing.Size(490, 540);
            this.Controls.Add(this.label5);
            this.Controls.Add(this.btnKiAngleDown);
            this.Controls.Add(this.btnKiAngleUp);
            this.Controls.Add(this.label4);
            this.Controls.Add(this.label2);
            this.Controls.Add(this.label3);
            this.Controls.Add(this.btnTiltForward);
            this.Controls.Add(this.btnTiltBackward);
            this.Controls.Add(this.btnKiSpeedDown);
            this.Controls.Add(this.btnKiSpeedUp);
            this.Controls.Add(this.txtSerialResult);
            this.Controls.Add(this.btnKpAngleDown);
            this.Controls.Add(this.btnKpAngleUp);
            this.Controls.Add(this.btnKpSpeedDown);
            this.Controls.Add(this.btnKpSpeedUp);
            this.Controls.Add(this.chkConnected);
            this.Controls.Add(this.btnStop);
            this.Controls.Add(this.groupBox1);
            this.Controls.Add(this.btnBuzzer);
            this.Controls.Add(this.btnBackward);
            this.Controls.Add(this.btnRight);
            this.Controls.Add(this.btnLeft);
            this.Controls.Add(this.btnForward);
            this.Controls.Add(this.label1);
            this.Controls.Add(this.cmbSerialPorts);
            this.Name = "MainUI";
            this.Text = "SerialCommander 2";
            this.FormClosing += new System.Windows.Forms.FormClosingEventHandler(this.frmClosing);
            this.groupBox1.ResumeLayout(false);
            this.groupBox1.PerformLayout();
            this.ResumeLayout(false);
            this.PerformLayout();

        }



        #endregion
        private ComboBox cmbSerialPorts;
        private Label label1;
        private Button btnForward;
        private Button btnLeft;
        private Button btnRight;
        private Button btnBackward;
        private Button btnBuzzer;
        private RadioButton radRemoteControl;
        private RadioButton radObstacleAvoidance;
        private RadioButton radOpenLab;
        private GroupBox groupBox1;
        private Button btnStop;
        private RadioButton btnStopBalancing;
        private CheckBox chkConnected;
        private Button btnKpSpeedUp;
        private Button btnKpSpeedDown;
        private Button btnKpAngleUp;
        private Button btnKpAngleDown;
        private TextBox txtSerialResult;
        private System.IO.Ports.SerialPort _serialPort;
        private Button btnKiSpeedUp;
        private Button btnKiSpeedDown;
        private Button btnTiltBackward;
        private Button btnTiltForward;
        private Label label3;
        private Label label2;
        private Label label4;
        private Button btnKiAngleUp;
        private Button btnKiAngleDown;
        private Label label5;
    }
}

