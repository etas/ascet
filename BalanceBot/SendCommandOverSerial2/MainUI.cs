using System;
using System.IO.Ports;
using System.Threading;
using System.Windows.Forms;

namespace SendCommandOverSerial
{
    public partial class MainUI : Form
    {

        public MainUI()
        {
            InitializeComponent();
 
            var ports = SerialPort.GetPortNames();
            // Create a new SerialPort object with default settings.

            btnStopBalancing.Checked = true;

            cmbSerialPorts.DataSource = ports;
            this._serialPort.DataReceived += new SerialDataReceivedEventHandler(SerialDataReceived);
        }

        private void frmClosing(object sender, EventArgs e)
        {
            _serialPort.Close();
        }

        private void ConnectSerialPort()
        {
            // Allow the user to set the appropriate properties.
            if (_serialPort.IsOpen)
                _serialPort.Close();
            _serialPort.PortName = cmbSerialPorts.SelectedItem.ToString();
            _serialPort.BaudRate = 115200;
            _serialPort.Parity = Parity.None;
            _serialPort.DataBits = 8;
            _serialPort.StopBits = StopBits.One;
            _serialPort.Handshake = Handshake.None;
            try
            {
                _serialPort.Open();
            }
            catch (Exception ex)
            {
                MessageBox.Show(ex.Message);
                chkConnected.Checked = false;
            }
        }

        private void WriteCommandToSerialPort(string command, SerialPort serialPort)
        {
            if (_serialPort.IsOpen)
                _serialPort.Write(command);
        }

        private void btnForward_Click(object sender, EventArgs e)
        {
            radRemoteControl.Checked = true;
            WriteCommandToSerialPort("a", _serialPort);
        }

        private void btnRight_MouseDown(object sender, EventArgs e)
        {
            radRemoteControl.Checked = true;
            WriteCommandToSerialPort("b", _serialPort);
        }

        private void btnRight_MouseUp(object sender, EventArgs e)
        {
            radRemoteControl.Checked = true;
            WriteCommandToSerialPort("q", _serialPort);
        }

        private void btnLeft_MouseDown(object sender, EventArgs e)
        {
            radRemoteControl.Checked = true;
            WriteCommandToSerialPort("c", _serialPort);
        }

        private void btnLeft_MouseUp(object sender, EventArgs e)
        {
            radRemoteControl.Checked = true;
            WriteCommandToSerialPort("q", _serialPort);
        }

        private void btnBackward_Click(object sender, EventArgs e)
        {
            radRemoteControl.Checked = true;
            WriteCommandToSerialPort("d", _serialPort);
        }

        private void btnBuzzer_MouseDown(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("h", _serialPort);
        }

        private void btnBuzzer_MouseUp(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("i", _serialPort);
        }

        private void radRemoteControl_CheckedChanged(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("e", _serialPort);
        }

        private void radObstacleAvoidance_CheckedChanged(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("f", _serialPort);
        }

        private void radOpenLab_CheckedChanged(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("g", _serialPort);
        }

        private void btnStop_Click(object sender, EventArgs e)
        {
            radRemoteControl.Checked = true;
            WriteCommandToSerialPort("e", _serialPort);
        }

        private void btnStopBalancing_CheckedChanged(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("j", _serialPort);
        }

        private void chkConnected_CheckedChanged(object sender, EventArgs e)
        {
            if (!chkConnected.Checked)
            {
                if (_serialPort.IsOpen)
                    _serialPort.Close();
            }
            else
            {
                ConnectSerialPort();
            }
        }

        private void btnKpSpeedUp_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("k", _serialPort);
        }

        private void btnKpSpeedDown_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("l", _serialPort);
        }

        private void btnKiSpeedUp_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("o", _serialPort);
        }

        private void btnKiSpeedDown_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("p", _serialPort);
        }

        private void btnKpAngleUp_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("m", _serialPort);
        }

        private void btnKpAngleDown_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("n", _serialPort);
        }

        private void btnKiAngleUp_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("t", _serialPort);
        }

        private void btnKiAngleDown_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("u", _serialPort);
        }

        private void WriteSerialData(string text)
        {
            txtSerialResult.Text += text;
        }

        private void SerialDataReceived(object sender, SerialDataReceivedEventArgs e)
        {
            SerialPort sp = sender as SerialPort;
            string received_Data = sp.ReadExisting();
            Invoke(new EventHandler(delegate
            {
                txtSerialResult.AppendText(received_Data);
            }));
        }

        private void btnTiltBackward_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("r", _serialPort);
        }

        private void btnTiltForward_Click(object sender, EventArgs e)
        {
            WriteCommandToSerialPort("s", _serialPort);
        }


    }
}
