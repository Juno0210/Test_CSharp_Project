using System;
using System.Collections.Generic;
using System.Linq;
using System.Numerics;
using System.Text;
using System.Threading.Tasks;
using System.Windows;
using System.Windows.Controls;
using System.Windows.Data;
using System.Windows.Documents;
using System.Windows.Input;
using System.Windows.Media;
using System.Windows.Media.Imaging;
using System.Windows.Navigation;
using System.Windows.Shapes;

namespace Pro1
{
    /// <summary>
    /// Interaction logic for MainWindow.xaml
    /// </summary>
    /// 
    
    public partial class MainWindow : Window
    {

        public char[] geometry_distribution = new char[4];
        public char[] hangingWall_data = new char[3];
        public char[] oreZone_data = new char[3];
        public char[] footWall_data = new char[3];
		public int flag = 0;
        public MainWindow()
        {
            InitializeComponent();
			

		}

        private void Window_Loaded(object sender, RoutedEventArgs e)
        {

			lbl1.Content = "       DEPARTMENT OF MINING ENGINEERING\nINDIAN INSTITUTE OF TECHNOLOGY KHARAGPUR\n      MINING METHOD SELECTION VERSION 1.0";
			cbmShape.Items.Add("Equi-dimensional/Massive");
			cbmShape.Items.Add("Platey-Tabular");
			cbmShape.Items.Add("Irregular");

			cbmGrade_distribution.Items.Add("Uniform");
			cbmGrade_distribution.Items.Add("Gradational");
			cbmGrade_distribution.Items.Add("Erratic");

			cbmHangingWallstrength.Items.Add("Weak");
			cbmHangingWallstrength.Items.Add("Moderate");
			cbmHangingWallstrength.Items.Add("Strong");

			cbmHangingWallfs.Items.Add("Very_Close");
			cbmHangingWallfs.Items.Add("Close");
			cbmHangingWallfs.Items.Add("Wide");
			cbmHangingWallfs.Items.Add("Very_Wide");

			cbmHangingWallfstr.Items.Add("Weak");
			cbmHangingWallfstr.Items.Add("Moderate");
			cbmHangingWallfstr.Items.Add("Strong");

			cbmOreZonestrenth.Items.Add("Weak");
			cbmOreZonestrenth.Items.Add("Moderate");
			cbmOreZonestrenth.Items.Add("Strong");

			cbmOreZonefs.Items.Add("Very_Close");
			cbmOreZonefs.Items.Add("Close");
			cbmOreZonefs.Items.Add("Wide");
			cbmOreZonefs.Items.Add("Very_Wide");

			cbmOreZonefstr.Items.Add("Weak");
			cbmOreZonefstr.Items.Add("Moderate");
			cbmOreZonefstr.Items.Add("Strong");

			cbmfootWallstrenth.Items.Add("Weak");
			cbmfootWallstrenth.Items.Add("Moderate");
			cbmfootWallstrenth.Items.Add("Strong");

			cbmfootWallfs.Items.Add("Very_Close");
			cbmfootWallfs.Items.Add("Close");
			cbmfootWallfs.Items.Add("Wide");
			cbmfootWallfs.Items.Add("Very_Wide");

			cbmfootWallfstr.Items.Add("Weak");
			cbmfootWallfstr.Items.Add("Moderate");
			cbmfootWallfstr.Items.Add("Strong");
			flag = 1;
			mainProcess();

        }

        public void mainProcess()
        {
			if (flag == 0)
				return;
            switch (cbmShape.SelectedIndex)
            {
                case 0:
                    
                    geometry_distribution[0] = 'M';
                    break;
                case 1:
                    geometry_distribution[0] = 'T';
                    break;
                case 2:
                    geometry_distribution[0] = 'I';
                    break;
            }

            double thickness = double.Parse(txtThickness.Text);
            string thickness_str = ore_thickness(thickness);
            if (thickness_str == "Narrow") 
                geometry_distribution[1] = 'N';
            else if (thickness_str == "intermediate") 
                geometry_distribution[1] = 'I';
            else if (thickness_str == "Thick") 
                geometry_distribution[1] = 'T';
            else if (thickness_str == "Very_thick") 
                geometry_distribution[1] = 'V';


            double angle = double.Parse(txtAngle.Text); 
            string angle_str = plunge(angle);
            if (angle_str == "Flat")
            {
                //        geometry_distribution.push_back('F');
                geometry_distribution[2] = 'F';
                
            }
            else if (angle_str == "intermediate")
            {
                //        geometry_distribution.push_back('I');
                geometry_distribution[2] = 'I';
                
            }
            else if (angle_str == "Steep")
            {
                //        geometry_distribution.push_back('S');
                geometry_distribution[2] = 'S';
                
            }
            switch (cbmGrade_distribution.SelectedIndex)
            {
                case 0:

                    geometry_distribution[3] = 'U';
                    break;
                case 1:
                    geometry_distribution[3] = 'G';
                    break;
                case 2:
                    geometry_distribution[3] = 'E';
                    break;
            }

            switch (cbmHangingWallstrength.SelectedIndex)
            {
                case 0:

                    hangingWall_data[0] = 'W';
                    break;
                case 1:
                    hangingWall_data[0] = 'M';
                    break;
                case 2:
                    hangingWall_data[0] = 'S';
                    break;
            }

            switch (cbmHangingWallfs.SelectedIndex)
            {
                case 0:

                    hangingWall_data[1] = 'V';
                    break;
                case 1:
                    hangingWall_data[1] = 'C';
                    break;
                case 2:
                    hangingWall_data[1] = 'W';
                    break;
                case 3:
                    hangingWall_data[1] = 'D';
                    break;
            }
            switch (cbmHangingWallfstr.SelectedIndex)
            {
                case 0:

                    hangingWall_data[2] = 'W';
                    break;
                case 1:
                    hangingWall_data[2] = 'M';
                    break;
                case 2:
                    hangingWall_data[2] = 'S';
                    break;

            }

            switch (cbmOreZonestrenth.SelectedIndex)
            {
                case 0:

                    oreZone_data[0] = 'W';
                    break;
                case 1:
                    oreZone_data[0] = 'M';
                    break;
                case 2:
                    oreZone_data[0] = 'S';
                    break;
            }

            switch (cbmOreZonefs.SelectedIndex)
            {
                case 0:

                    oreZone_data[1] = 'V';
                    break;
                case 1:
                    oreZone_data[1] = 'C';
                    break;
                case 2:
                    oreZone_data[1] = 'W';
                    break;
                case 3:
                    oreZone_data[1] = 'D';
                    break;
            }
            switch (cbmOreZonefstr.SelectedIndex)
            {
                case 0:

                    oreZone_data[2] = 'W';
                    break;
                case 1:
                    oreZone_data[2] = 'M';
                    break;
                case 2:
                    oreZone_data[2] = 'S';
                    break;

            }

            switch (cbmfootWallstrenth.SelectedIndex)
            {
                case 0:

                    footWall_data[0] = 'W';
                    break;
                case 1:
                    footWall_data[0] = 'M';
                    break;
                case 2:
                    footWall_data[0] = 'S';
                    break;
            }

            switch (cbmfootWallfs.SelectedIndex)
            {
                case 0:

                    footWall_data[1] = 'V';
                    break;
                case 1:
                    footWall_data[1] = 'C';
                    break;
                case 2:
                    footWall_data[1] = 'W';
                    break;
                case 3:
                    footWall_data[1] = 'D';
                    break;
            }
            switch (cbmfootWallfstr.SelectedIndex)
            {
                case 0:

                    footWall_data[2] = 'W';
                    break;
                case 1:
                    footWall_data[2] = 'M';
                    break;
                case 2:
                    footWall_data[2] = 'S';
                    break;

            }

            double OPEN_PIT, BLOCK_CAVING, SUBLEVEL_STOPING, SUBLEVEL_CAVING, LONG_WALL, ROOM_PILLAR, SHRINKAGE_STOPING, CUT_FILL, TOP_SLICING, SQUARE_SET;
            OPEN_PIT = openPit_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            //	cout<<OPEN_PIT;
            BLOCK_CAVING = blockCaving_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            // cout<<BLOCK_CAVING<<endl;
            SUBLEVEL_STOPING = sublevelStoping_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            // cout<<SUBLEVEL_STOPING<<endl;
            SUBLEVEL_CAVING = sublevelCaving_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            // cout<<SUBLEVEL_CAVING<<endl;
            LONG_WALL = longwall_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            // cout<<LONG_WALL<<endl;
            ROOM_PILLAR = roomPillar_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            // cout<<ROOM_PILLAR<<endl;
            SHRINKAGE_STOPING = shrinkageStoping_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            // cout<<SHRINKAGE_STOPING<<endl;
            CUT_FILL = cutFill_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            // cout<<CUT_FILL<<endl;
            TOP_SLICING = topSlicing_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
            // cout<<TOP_SLICING<<endl;
            SQUARE_SET = squareSet_calc(geometry_distribution, hangingWall_data, oreZone_data, footWall_data);
			//PriorityQueue<pair<double, string>> pq;

			//lblMethod.Content = "Method : \t" + geometry_distribution[0] + "\t" + geometry_distribution[1] + "\t" + geometry_distribution[2] + "\t" + geometry_distribution[3];

			List<MyItem> data = new List<MyItem>();
			
			data.Add(new MyItem { Value = OPEN_PIT, Name = "OPEN_PIT" });
			data.Add(new MyItem { Value = BLOCK_CAVING, Name = "BLOCK_CAVING" });
			data.Add(new MyItem { Value = SUBLEVEL_STOPING, Name = "SUBLEVEL_STOPING" });
			data.Add(new MyItem { Value = SUBLEVEL_CAVING, Name = "SUBLEVEL_CAVING" });
			data.Add(new MyItem { Value = LONG_WALL, Name = "LONG_WALL" });
			data.Add(new MyItem { Value = ROOM_PILLAR, Name = "ROOM_PILLAR" });
			data.Add(new MyItem { Value = SHRINKAGE_STOPING, Name = "SHRINKAGE_STOPING" });
			data.Add(new MyItem { Value = CUT_FILL, Name = "CUT_FILL" });
			data.Add(new MyItem { Value = TOP_SLICING, Name = "TOP_SLICING" });
			data.Add(new MyItem { Value = SQUARE_SET, Name = "SQUARE_SET" });
			data.Sort((x, y) => y.Value.CompareTo(x.Value));

			resultListView.Items.Clear();
			foreach (var item in data)
            {
				resultListView.Items.Add(item);
			}
			
			





			//resultListView.Columns.Add("S.No")

		}

		internal class MyItem
		{
			public double Value { get; set; }

			public string Name { get; set; }
		}
		double square_set(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += 0;
			else if (geometry_distribution[0] == 'T') sum += 2;
			else if (geometry_distribution[0] == 'I') sum += 4;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += 4;
			else if (geometry_distribution[1] == 'I') sum += 4;
			else if (geometry_distribution[1] == 'T') sum += 1;
			else if (geometry_distribution[1] == 'V') sum += 1;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 2;
			else if (geometry_distribution[2] == 'I') sum += 3;
			else if (geometry_distribution[2] == 'S') sum += 3;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 3;
			else if (geometry_distribution[3] == 'G') sum += 3;
			else if (geometry_distribution[3] == 'E') sum += 3;
			return sum;
		}

		//square set
		double square_set_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 3;
			else if (hangingWall_data[0] == 'M') sum += 2;
			else if (hangingWall_data[0] == 'S') sum += 2;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 3;
			else if (hangingWall_data[1] == 'C') sum += 3;
			else if (hangingWall_data[1] == 'W') sum += 2;
			else if (hangingWall_data[1] == 'D') sum += 2;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 4;
			else if (hangingWall_data[2] == 'M') sum += 3;
			else if (hangingWall_data[2] == 'S') sum += 2;

			return sum;
		}

		//square cut
		double square_set_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 4;
			else if (oreZone_data[0] == 'M') sum += 1;
			else if (oreZone_data[0] == 'S') sum += 1;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 4;
			else if (oreZone_data[1] == 'C') sum += 4;
			else if (oreZone_data[1] == 'W') sum += 2;
			else if (oreZone_data[1] == 'D') sum += 1;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 4;
			else if (oreZone_data[2] == 'M') sum += 3;
			else if (oreZone_data[2] == 'S') sum += 2;

			return sum;
		}

		//Square set
		double square_set_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 4;
			else if (footWall_data[0] == 'M') sum += 2;
			else if (footWall_data[0] == 'S') sum += 2;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 4;
			else if (footWall_data[1] == 'C') sum += 4;
			else if (footWall_data[1] == 'W') sum += 2;
			else if (footWall_data[1] == 'D') sum += 2;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 4;
			else if (footWall_data[2] == 'M') sum += 4;
			else if (footWall_data[2] == 'S') sum += 2;

			return sum;
		}

		//calculation for square set
		double squareSet_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += square_set(geometry_distribution);

			sum += square_set_hanging_wall(hangingWall_data);

			sum += square_set_ore_zone(oreZone_data);

			sum += square_set_foot_wall(footWall_data);

			return sum;
		}

		// 9-Top SLicing
		double top_slicing(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += 3;
			else if (geometry_distribution[0] == 'T') sum += 3;
			else if (geometry_distribution[0] == 'I') sum += 0;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += -49;
			else if (geometry_distribution[1] == 'I') sum += 0;
			else if (geometry_distribution[1] == 'T') sum += 3;
			else if (geometry_distribution[1] == 'V') sum += 4;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 4;
			else if (geometry_distribution[2] == 'I') sum += 1;
			else if (geometry_distribution[2] == 'S') sum += 2;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 4;
			else if (geometry_distribution[3] == 'G') sum += 2;
			else if (geometry_distribution[3] == 'E') sum += 0;
			return sum;
		}

		//top slicing
		double top_slicing_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 4;
			else if (hangingWall_data[0] == 'M') sum += 2;
			else if (hangingWall_data[0] == 'S') sum += 1;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 3;
			else if (hangingWall_data[1] == 'C') sum += 3;
			else if (hangingWall_data[1] == 'W') sum += 3;
			else if (hangingWall_data[1] == 'D') sum += 0;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 4;
			else if (hangingWall_data[2] == 'M') sum += 2;
			else if (hangingWall_data[2] == 'S') sum += 0;

			return sum;
		}

		//top slicing
		double top_slicing_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 2;
			else if (oreZone_data[0] == 'M') sum += 3;
			else if (oreZone_data[0] == 'S') sum += 3;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 1;
			else if (oreZone_data[1] == 'C') sum += 1;
			else if (oreZone_data[1] == 'W') sum += 2;
			else if (oreZone_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 1;
			else if (oreZone_data[2] == 'M') sum += 2;
			else if (oreZone_data[2] == 'S') sum += 4;

			return sum;
		}

		//top slicing

		double top_slicing_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 2;
			else if (footWall_data[0] == 'M') sum += 3;
			else if (footWall_data[0] == 'S') sum += 3;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 1;
			else if (footWall_data[1] == 'C') sum += 3;
			else if (footWall_data[1] == 'W') sum += 3;
			else if (footWall_data[1] == 'D') sum += 3;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 1;
			else if (footWall_data[2] == 'M') sum += 2;
			else if (footWall_data[2] == 'S') sum += 3;

			return sum;
		}

		//calculation for top slicing
		double topSlicing_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += top_slicing(geometry_distribution);

			sum += top_slicing_hanging_wall(hangingWall_data);

			sum += top_slicing_ore_zone(oreZone_data);

			sum += top_slicing_foot_wall(footWall_data);

			return sum;
		}

		//cut and fill
		double cut_fill_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 4;
			else if (footWall_data[0] == 'M') sum += 2;
			else if (footWall_data[0] == 'S') sum += 2;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 4;
			else if (footWall_data[1] == 'C') sum += 4;
			else if (footWall_data[1] == 'W') sum += 2;
			else if (footWall_data[1] == 'D') sum += 2;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 4;
			else if (footWall_data[2] == 'M') sum += 4;
			else if (footWall_data[2] == 'S') sum += 2;

			return sum;
		}
		//cut and fill
		double cut_fill_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 3;
			else if (oreZone_data[0] == 'M') sum += 2;
			else if (oreZone_data[0] == 'S') sum += 2;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 3;
			else if (oreZone_data[1] == 'C') sum += 3;
			else if (oreZone_data[1] == 'W') sum += 2;
			else if (oreZone_data[1] == 'D') sum += 2;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 3;
			else if (oreZone_data[2] == 'M') sum += 3;
			else if (oreZone_data[2] == 'S') sum += 2;

			return sum;
		}
		//cut and fill
		double cut_fill_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 3;
			else if (hangingWall_data[0] == 'M') sum += 2;
			else if (hangingWall_data[0] == 'S') sum += 2;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 3;
			else if (hangingWall_data[1] == 'C') sum += 3;
			else if (hangingWall_data[1] == 'W') sum += 2;
			else if (hangingWall_data[1] == 'D') sum += 2;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 4;
			else if (hangingWall_data[2] == 'M') sum += 3;
			else if (hangingWall_data[2] == 'S') sum += 2;

			return sum;
		}
		// 8-Cut and Fill
		double cut_fill(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += 0;
			else if (geometry_distribution[0] == 'T') sum += 4;
			else if (geometry_distribution[0] == 'I') sum += 2;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += 4;
			else if (geometry_distribution[1] == 'I') sum += 4;
			else if (geometry_distribution[1] == 'T') sum += 0;
			else if (geometry_distribution[1] == 'V') sum += 0;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 0;
			else if (geometry_distribution[2] == 'I') sum += 3;
			else if (geometry_distribution[2] == 'S') sum += 4;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 3;
			else if (geometry_distribution[3] == 'G') sum += 3;
			else if (geometry_distribution[3] == 'E') sum += 3;
			return sum;
		}
		//calculation cut and fill
		double cutFill_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += cut_fill(geometry_distribution);

			sum += cut_fill_hanging_wall(hangingWall_data);

			sum += cut_fill_ore_zone(oreZone_data);

			sum += cut_fill_foot_wall(footWall_data);

			return sum;
		}


		//Shrinkage stoping
		double shrinkage_stoping_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 4;
			else if (hangingWall_data[0] == 'M') sum += 2;
			else if (hangingWall_data[0] == 'S') sum += 1;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 4;
			else if (hangingWall_data[1] == 'C') sum += 4;
			else if (hangingWall_data[1] == 'W') sum += 3;
			else if (hangingWall_data[1] == 'D') sum += 0;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 4;
			else if (hangingWall_data[2] == 'M') sum += 2;
			else if (hangingWall_data[2] == 'S') sum += 0;

			return sum;
		}

		//Shrinkage stoping
		double shrinkage_stoping_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 1;
			else if (oreZone_data[0] == 'M') sum += 3;
			else if (oreZone_data[0] == 'S') sum += 4;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 0;
			else if (oreZone_data[1] == 'C') sum += 1;
			else if (oreZone_data[1] == 'W') sum += 3;
			else if (oreZone_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 0;
			else if (oreZone_data[2] == 'M') sum += 2;
			else if (oreZone_data[2] == 'S') sum += 4;

			return sum;
		}

		//Shrinkage Stoping
		double shrinkage_stoping_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 2;
			else if (footWall_data[0] == 'M') sum += 3;
			else if (footWall_data[0] == 'S') sum += 3;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 2;
			else if (footWall_data[1] == 'C') sum += 3;
			else if (footWall_data[1] == 'W') sum += 3;
			else if (footWall_data[1] == 'D') sum += 2;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 2;
			else if (footWall_data[2] == 'M') sum += 2;
			else if (footWall_data[2] == 'S') sum += 3;

			return sum;
		}


		// 7-Shrinkage Stoping
		double shrinkage_stoping(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += 2;
			else if (geometry_distribution[0] == 'T') sum += 2;
			else if (geometry_distribution[0] == 'I') sum += 1;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += 1;
			else if (geometry_distribution[1] == 'I') sum += 2;
			else if (geometry_distribution[1] == 'T') sum += 4;
			else if (geometry_distribution[1] == 'V') sum += 3;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 2;
			else if (geometry_distribution[2] == 'I') sum += 1;
			else if (geometry_distribution[2] == 'S') sum += 4;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 3;
			else if (geometry_distribution[3] == 'G') sum += 2;
			else if (geometry_distribution[3] == 'E') sum += 1;
			return sum;
		}
		//calculation for shrinkage stoping
		double shrinkageStoping_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += shrinkage_stoping(geometry_distribution);

			sum += shrinkage_stoping_hanging_wall(hangingWall_data);

			sum += shrinkage_stoping_ore_zone(oreZone_data);

			sum += shrinkage_stoping_foot_wall(footWall_data);

			return sum;
		}

		//Room and Pillar
		double room_pillar_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 0;
			else if (footWall_data[0] == 'M') sum += 2;
			else if (footWall_data[0] == 'S') sum += 4;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 0;
			else if (footWall_data[1] == 'C') sum += 1;
			else if (footWall_data[1] == 'W') sum += 3;
			else if (footWall_data[1] == 'D') sum += 3;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 0;
			else if (footWall_data[2] == 'M') sum += 3;
			else if (footWall_data[2] == 'S') sum += 3;

			return sum;
		}
		double room_pillar_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 0;
			else if (oreZone_data[0] == 'M') sum += 3;
			else if (oreZone_data[0] == 'S') sum += 4;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 0;
			else if (oreZone_data[1] == 'C') sum += 1;
			else if (oreZone_data[1] == 'W') sum += 2;
			else if (oreZone_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 0;
			else if (oreZone_data[2] == 'M') sum += 2;
			else if (oreZone_data[2] == 'S') sum += 4;

			return sum;
		}

		//Room and pillar
		double room_pillar_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 0;
			else if (hangingWall_data[0] == 'M') sum += 3;
			else if (hangingWall_data[0] == 'S') sum += 4;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 0;
			else if (hangingWall_data[1] == 'C') sum += 1;
			else if (hangingWall_data[1] == 'W') sum += 2;
			else if (hangingWall_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 0;
			else if (hangingWall_data[2] == 'M') sum += 2;
			else if (hangingWall_data[2] == 'S') sum += 4;

			return sum;
		}
		// 6-Room And Pillar
		double room_pillar(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += 0;
			else if (geometry_distribution[0] == 'T') sum += 4;
			else if (geometry_distribution[0] == 'I') sum += 2;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += 4;
			else if (geometry_distribution[1] == 'I') sum += 2;
			else if (geometry_distribution[1] == 'T') sum += -49;
			else if (geometry_distribution[1] == 'V') sum += -49;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 4;
			else if (geometry_distribution[2] == 'I') sum += 1;
			else if (geometry_distribution[2] == 'S') sum += 0;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 3;
			else if (geometry_distribution[3] == 'G') sum += 3;
			else if (geometry_distribution[3] == 'E') sum += 3;
			return sum;
		}

		//calculation for room and pillar
		double roomPillar_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += room_pillar(geometry_distribution);

			sum += room_pillar_hanging_wall(hangingWall_data);

			sum += room_pillar_ore_zone(oreZone_data);

			sum += room_pillar_foot_wall(footWall_data);

			return sum;
		}

		//longwall
		double longwall_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 2;
			else if (footWall_data[0] == 'M') sum += 3;
			else if (footWall_data[0] == 'S') sum += 3;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 1;
			else if (footWall_data[1] == 'C') sum += 2;
			else if (footWall_data[1] == 'W') sum += 4;
			else if (footWall_data[1] == 'D') sum += 3;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 1;
			else if (footWall_data[2] == 'M') sum += 3;
			else if (footWall_data[2] == 'S') sum += 3;

			return sum;
		}
		//long wall
		double longwall_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 4;
			else if (oreZone_data[0] == 'M') sum += 1;
			else if (oreZone_data[0] == 'S') sum += 0;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 4;
			else if (oreZone_data[1] == 'C') sum += 4;
			else if (oreZone_data[1] == 'W') sum += 0;
			else if (oreZone_data[1] == 'D') sum += 0;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 4;
			else if (oreZone_data[2] == 'M') sum += 3;
			else if (oreZone_data[2] == 'S') sum += 0;

			return sum;
		}
		double longwall_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 4;
			else if (hangingWall_data[0] == 'M') sum += 2;
			else if (hangingWall_data[0] == 'S') sum += 0;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 4;
			else if (hangingWall_data[1] == 'C') sum += 4;
			else if (hangingWall_data[1] == 'W') sum += 3;
			else if (hangingWall_data[1] == 'D') sum += 0;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 4;
			else if (hangingWall_data[2] == 'M') sum += 2;
			else if (hangingWall_data[2] == 'S') sum += 0;

			return sum;
		}
		double long_wall(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += -49;
			else if (geometry_distribution[0] == 'T') sum += 4;
			else if (geometry_distribution[0] == 'I') sum += -49;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += 4;
			else if (geometry_distribution[1] == 'I') sum += 0;
			else if (geometry_distribution[1] == 'T') sum += -49;
			else if (geometry_distribution[1] == 'V') sum += -49;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 4;
			else if (geometry_distribution[2] == 'I') sum += 0;
			else if (geometry_distribution[2] == 'S') sum += -49;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 4;
			else if (geometry_distribution[3] == 'G') sum += 2;
			else if (geometry_distribution[3] == 'E') sum += 0;
			return sum;
		}
		//calculation for block caving
		// 3-Sublevel Stoping

		// room and Pillar

		double longwall_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += long_wall(geometry_distribution);

			sum += longwall_hanging_wall(hangingWall_data);

			sum += longwall_ore_zone(oreZone_data);

			sum += longwall_foot_wall(footWall_data);

			return sum;
		}
		double sublevel_stoping(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += 2;
			else if (geometry_distribution[0] == 'T') sum += 2;
			else if (geometry_distribution[0] == 'I') sum += 1;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += 1;
			else if (geometry_distribution[1] == 'I') sum += 2;
			else if (geometry_distribution[1] == 'T') sum += 4;
			else if (geometry_distribution[1] == 'V') sum += 3;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 2;
			else if (geometry_distribution[2] == 'I') sum += 1;
			else if (geometry_distribution[2] == 'S') sum += 4;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 3;
			else if (geometry_distribution[3] == 'G') sum += 3;
			else if (geometry_distribution[3] == 'E') sum += 1;
			return sum;
		}

		//Sublevel Stoping
		double sublevel_stoping_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += -49;
			else if (oreZone_data[0] == 'M') sum += 3;
			else if (oreZone_data[0] == 'S') sum += 4;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 0;
			else if (oreZone_data[1] == 'C') sum += 0;
			else if (oreZone_data[1] == 'W') sum += 1;
			else if (oreZone_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 0;
			else if (oreZone_data[2] == 'M') sum += 2;
			else if (oreZone_data[2] == 'S') sum += 4;

			return sum;
		}

		//sublevel stoping
		double sublevel_stoping_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 0;
			else if (footWall_data[0] == 'M') sum += 2;
			else if (footWall_data[0] == 'S') sum += 4;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 0;
			else if (footWall_data[1] == 'C') sum += 0;
			else if (footWall_data[1] == 'W') sum += 2;
			else if (footWall_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 0;
			else if (footWall_data[2] == 'M') sum += 1;
			else if (footWall_data[2] == 'S') sum += 4;

			return sum;
		}
		double sublevel_stoping_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += -49;
			else if (hangingWall_data[0] == 'M') sum += 3;
			else if (hangingWall_data[0] == 'S') sum += 4;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += -49;
			else if (hangingWall_data[1] == 'C') sum += 0;
			else if (hangingWall_data[1] == 'W') sum += 1;
			else if (hangingWall_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 0;
			else if (hangingWall_data[2] == 'M') sum += 2;
			else if (hangingWall_data[2] == 'S') sum += 4;

			return sum;
		}



		// sublevel caving
		double sublevel_caving_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 0;
			else if (oreZone_data[0] == 'M') sum += 3;
			else if (oreZone_data[0] == 'S') sum += 3;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 0;
			else if (oreZone_data[1] == 'C') sum += 2;
			else if (oreZone_data[1] == 'W') sum += 4;
			else if (oreZone_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 0;
			else if (oreZone_data[2] == 'M') sum += 2;
			else if (oreZone_data[2] == 'S') sum += 2;

			return sum;
		}
		double sublevel_caving_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 0;
			else if (footWall_data[0] == 'M') sum += 2;
			else if (footWall_data[0] == 'S') sum += 4;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 0;
			else if (footWall_data[1] == 'C') sum += 1;
			else if (footWall_data[1] == 'W') sum += 3;
			else if (footWall_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 0;
			else if (footWall_data[2] == 'M') sum += 2;
			else if (footWall_data[2] == 'S') sum += 4;

			return sum;
		}
		// 4-Sublevel Caving
		double sublevel_caving(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += 3;
			else if (geometry_distribution[0] == 'T') sum += 4;
			else if (geometry_distribution[0] == 'I') sum += 1;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += -49;
			else if (geometry_distribution[1] == 'I') sum += 0;
			else if (geometry_distribution[1] == 'T') sum += 4;
			else if (geometry_distribution[1] == 'V') sum += 4;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 1;
			else if (geometry_distribution[2] == 'I') sum += 1;
			else if (geometry_distribution[2] == 'S') sum += 4;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 4;
			else if (geometry_distribution[3] == 'G') sum += 2;
			else if (geometry_distribution[3] == 'E') sum += 0;
			return sum;
		}
		// sublevel caving
		double sublevel_caving_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 3;
			else if (hangingWall_data[0] == 'M') sum += 2;
			else if (hangingWall_data[0] == 'S') sum += 1;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 3;
			else if (hangingWall_data[1] == 'C') sum += 4;
			else if (hangingWall_data[1] == 'W') sum += 3;
			else if (hangingWall_data[1] == 'D') sum += 1;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 4;
			else if (hangingWall_data[2] == 'M') sum += 2;
			else if (hangingWall_data[2] == 'S') sum += 0;

			return sum;
		}


		//calculation for sublevel caving
		double sublevelCaving_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += sublevel_caving(geometry_distribution);

			sum += sublevel_caving_hanging_wall(hangingWall_data);

			sum += sublevel_caving_ore_zone(oreZone_data);

			sum += sublevel_caving_foot_wall(footWall_data);

			return sum;
		}

		double sublevelStoping_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += sublevel_stoping(geometry_distribution);

			sum += sublevel_stoping_hanging_wall(hangingWall_data);

			sum += sublevel_stoping_ore_zone(oreZone_data);

			sum += sublevel_stoping_foot_wall(footWall_data);

			return sum;
		}
		string ore_thickness(double thickness)
		{
			if (thickness < 10) return "Narrow";
			else if (thickness >= 10 && thickness < 30) return "intermediate";
			else if (thickness >= 30 && thickness < 100) return "Thick";
			else return "Very_thick";
		}


		double open_pit_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 3;
			else if (footWall_data[0] == 'M') sum += 4;
			else if (footWall_data[0] == 'S') sum += 4;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 2;
			else if (footWall_data[1] == 'C') sum += 3;
			else if (footWall_data[1] == 'W') sum += 4;
			else if (footWall_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 2;
			else if (footWall_data[2] == 'M') sum += 3;
			else if (footWall_data[2] == 'S') sum += 4;

			return sum;
		}

		double open_pit_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 3;
			else if (oreZone_data[0] == 'M') sum += 4;
			else if (oreZone_data[0] == 'S') sum += 4;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 2;
			else if (oreZone_data[1] == 'C') sum += 3;
			else if (oreZone_data[1] == 'W') sum += 4;
			else if (oreZone_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 2;
			else if (oreZone_data[2] == 'M') sum += 3;
			else if (oreZone_data[2] == 'S') sum += 4;

			return sum;
		}

		double open_pit_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 3;
			else if (hangingWall_data[0] == 'M') sum += 4;
			else if (hangingWall_data[0] == 'S') sum += 4;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 2;
			else if (hangingWall_data[1] == 'C') sum += 3;
			else if (hangingWall_data[1] == 'W') sum += 4;
			else if (hangingWall_data[1] == 'D') sum += 4;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 2;
			else if (hangingWall_data[2] == 'M') sum += 3;
			else if (hangingWall_data[2] == 'S') sum += 4;

			return sum;
		}
		double open_pit(char[] geometry_distribution)
		{
			//	double sum=0;
			// general Shape
			// massive tabular irregular
			//	cout<<1;
			double sum = 0;
			if (geometry_distribution[0] == 'M') sum += 3;
			else if (geometry_distribution[0] == 'T') sum += 2;
			else if (geometry_distribution[0] == 'I') sum += 3;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += 2;
			else if (geometry_distribution[1] == 'I') sum += 3;
			else if (geometry_distribution[1] == 'T') sum += 4;
			else if (geometry_distribution[1] == 'V') sum += 4;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 3;
			else if (geometry_distribution[2] == 'I') sum += 3;
			else if (geometry_distribution[2] == 'S') sum += 4;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 3;
			else if (geometry_distribution[3] == 'G') sum += 3;
			else if (geometry_distribution[3] == 'E') sum += 3;
			return sum;
		}

		double openPit_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += open_pit(geometry_distribution);

			sum += open_pit_hanging_wall(hangingWall_data);

			sum += open_pit_ore_zone(oreZone_data);

			sum += open_pit_foot_wall(footWall_data);

			return sum;
		}
		double block_caving(char[] geometry_distribution)
		{
			double sum = 0;
			// general Shape
			// massive tabular irregular
			if (geometry_distribution[0] == 'M') sum += 4;
			else if (geometry_distribution[0] == 'T') sum += 2;
			else if (geometry_distribution[0] == 'I') sum += 3;
			// ore thickness
			// narrow doubleermediate thick very thick
			if (geometry_distribution[1] == 'N') sum += -49;
			else if (geometry_distribution[1] == 'I') sum += 0;
			else if (geometry_distribution[1] == 'T') sum += 2;
			else if (geometry_distribution[1] == 'V') sum += 4;
			// Ore Plunge
			// flat doubleermediate steep
			if (geometry_distribution[2] == 'F') sum += 3;
			else if (geometry_distribution[2] == 'I') sum += 2;
			else if (geometry_distribution[2] == 'S') sum += 4;
			// grade distribution
			// uniform gradational erratic
			if (geometry_distribution[3] == 'U') sum += 4;
			else if (geometry_distribution[3] == 'G') sum += 2;
			else if (geometry_distribution[3] == 'E') sum += 0;
			return sum;
		}

		double block_caving_hanging_wall(char[] hangingWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (hangingWall_data[0] == 'W') sum += 4;
			else if (hangingWall_data[0] == 'M') sum += 2;
			else if (hangingWall_data[0] == 'S') sum += 1;

			//Fracture strength
			if (hangingWall_data[1] == 'V') sum += 3;
			else if (hangingWall_data[1] == 'C') sum += 4;
			else if (hangingWall_data[1] == 'W') sum += 3;
			else if (hangingWall_data[1] == 'D') sum += 0;
			//
			//Fracture Strength
			if (hangingWall_data[2] == 'W') sum += 4;
			else if (hangingWall_data[2] == 'M') sum += 2;
			else if (hangingWall_data[2] == 'S') sum += 0;

			return sum;
		}
		double block_caving_ore_zone(char[] oreZone_data)
		{
			//rock substance strength
			double sum = 0;
			if (oreZone_data[0] == 'W') sum += 4;
			else if (oreZone_data[0] == 'M') sum += 1;
			else if (oreZone_data[0] == 'S') sum += 1;

			//Fracture strength
			if (oreZone_data[1] == 'V') sum += 4;
			else if (oreZone_data[1] == 'C') sum += 4;
			else if (oreZone_data[1] == 'W') sum += 3;
			else if (oreZone_data[1] == 'D') sum += 0;
			//
			//Fracture Strength
			if (oreZone_data[2] == 'W') sum += 4;
			else if (oreZone_data[2] == 'M') sum += 3;
			else if (oreZone_data[2] == 'S') sum += 0;

			return sum;
		}
		double block_caving_foot_wall(char[] footWall_data)
		{
			//rock substance strength
			double sum = 0;
			if (footWall_data[0] == 'W') sum += 2;
			else if (footWall_data[0] == 'M') sum += 3;
			else if (footWall_data[0] == 'S') sum += 3;

			//Fracture strength
			if (footWall_data[1] == 'V') sum += 1;
			else if (footWall_data[1] == 'C') sum += 3;
			else if (footWall_data[1] == 'W') sum += 3;
			else if (footWall_data[1] == 'D') sum += 3;
			//
			//Fracture Strength
			if (footWall_data[2] == 'W') sum += 1;
			else if (footWall_data[2] == 'M') sum += 3;
			else if (footWall_data[2] == 'S') sum += 3;

			return sum;
		}
		double blockCaving_calc(char[] geometry_distribution, char[] hangingWall_data, char[] oreZone_data, char[] footWall_data)
		{

			double sum = 0;
			sum += block_caving(geometry_distribution);

			sum += block_caving_hanging_wall(hangingWall_data);

			sum += block_caving_ore_zone(oreZone_data);

			sum += block_caving_foot_wall(footWall_data);

			return sum;
		}

		string plunge(double angle)
        {
            if (angle < 20) return "Flat";
            else if (angle >= 20 && angle < 55) return "intermediate";
            else return "Steep";
        }

        private void cbm_SelectionChanged(object sender, SelectionChangedEventArgs e)
        {
			mainProcess();
        }

       

        private void txt_TextChanged(object sender, TextChangedEventArgs e)
        {
			mainProcess();
		}
    }
}
