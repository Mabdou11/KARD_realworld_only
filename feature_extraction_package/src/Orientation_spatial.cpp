#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <stdio.h>
#include <math.h>
#include <fstream>
#include <openni_tracker_SVM/msg_SVM.h>
#include <std_msgs/Float64.h>


using namespace std;
#define PI 3.14159265
#define taille 3

//ros::Publisher pub;
ros::Subscriber sub;

float qx,qy,qz,qw; 
    double sqw;    
    double sqx;    
    double sqy;    
    double sqz; 
    
         vector<double> pose_x;
         vector<double> pose_y;
         vector<double> motion_vect;
         
      float  pose_z_tmp, pose_x_tmp, pose_y_tmp;

 void motion_compt(const std_msgs::Float64::ConstPtr& msg)
{  
         ros::NodeHandle h1;

      ROS_INFO("motion quantity: [%f]", msg->data);
      motion_vect.push_back(msg->data);
        // std_msgs::Float64  angle;
        // ros::Publisher pub;
        //pub= h1.advertise<std_msgs::Float64>("orientation",1);
       
      /*   qx=msg->qx;
         qy=msg->qy;
         qz=msg->qz;
         qw=msg->qw;
  
    sqw = qw*qw;    
    sqx = qx*qx;    
    sqy = qy*qy;    
    sqz = qz*qz; 

    pose_x_tmp =  (atan2(2.0 * (qy*qz + qx*qw),(-sqx - sqy + sqz + sqw)) * (180.0f/PI));          
    pose_y_tmp =  (asin(-2.0 * (qx*qz - qy*qw)) * (180.0f/PI));
    pose_z_tmp =  (atan2(2.0 * (qx*qy + qz*qw),(sqx - sqy - sqz + sqw)) * (180.0f/PI));
   // angle.data= pose_z_tmp;
  // cout << "pose_z_tmp "<< pose_z_tmp <<endl;
   //cout << "qx "<< qx <<endl;
  pose_x.push_back(pose_x_tmp);
  pose_y.push_back(pose_y_tmp);
  pose_z.push_back(pose_z_tmp);
cout <<"POSE PUSHED INTO VECTOR" <<endl;

//if (pose_z_tmp<30 && pose_z_tmp >-30) cout<<"La Pose de l'utilisateur est  : Face !!" << pose_z_tmp <<endl;
    
//if(pose_z_tmp>=30 && pose_z_tmp<150) cout<<"La Pose de l'utilisateur est  : Droite !!"<< pose_z_tmp <<endl;   

//if(pose_z_tmp<-30 && pose_z_tmp-150) cout<<"La Pose de l'utilisateur est  : Gauche !!"<< pose_z_tmp<<endl;

//if(pose_z_tmp>=150 ) cout<<"La Pose de l'utilisateur est  : Dos !!"<< pose_z_tmp <<endl;
   
//if (pose_z_tmp<=-150) cout<<"La Pose de l'utilisateur est  : Dos !!"<< pose_z_tmp <<endl;  

 
pub.publish(angle);*/
  
  }
////////////////////////////////////////////////////////////////////////////

int main(int argc, char** argv){
	
	ros::init(argc, argv, "my_tf_listener");
       
	ros::NodeHandle node, h2;
	tf::TransformListener listener;

	ros::Rate rate(30.0);
        float frame_rate=1/30.0;
         
	vector<double> right_hand_x;	vector<double> right_hand_roll;
	vector<double> right_hand_y;	vector<double> right_hand_pitch;	
	vector<double> right_hand_z;	vector<double> right_hand_yaw;  

	vector<double> left_hand_x;     vector<double> left_hand_roll;
	vector<double> left_hand_y;     vector<double> left_hand_pitch;
	vector<double> left_hand_z;     vector<double> left_hand_yaw;

        vector<double> right_elbow_x;   vector<double> right_elbow_roll;
	vector<double> right_elbow_y;   vector<double> right_elbow_pitch;
	vector<double> right_elbow_z;   vector<double> right_elbow_yaw;

        vector<double> left_elbow_x;   vector<double> left_elbow_roll;
	vector<double> left_elbow_y;   vector<double> left_elbow_pitch;
	vector<double> left_elbow_z;   vector<double> left_elbow_yaw;

        vector<double> right_shoulder_x;   vector<double> right_shoulder_roll;
	vector<double> right_shoulder_y;   vector<double> right_shoulder_pitch;
	vector<double> right_shoulder_z;   vector<double> right_shoulder_yaw;
  
        vector<double> left_shoulder_x;   vector<double> left_shoulder_roll;
	vector<double> left_shoulder_y;   vector<double> left_shoulder_pitch;
	vector<double> left_shoulder_z;   vector<double> left_shoulder_yaw;
     
	vector<double> head_x;    vector<double> head_roll;
	vector<double> head_y;    vector<double> head_pitch;
	vector<double> head_z;    vector<double> head_yaw;      

        vector<double> neck_x;    vector<double> neck_roll;
	vector<double> neck_y;    vector<double> neck_pitch;
	vector<double> neck_z;    vector<double> neck_yaw;

	vector<double>  Vec_Angle_Head_Neck_Torso, Vec_Angle_Neck_RShoulder_RElbow,Vec_Angle_RShoulder_RElbow_RHand,Vec_Angle_Neck_LShoulder_LElbow,Vec_Angle_LShoulder_LElbow_LHand;
    
  geometry_msgs::Point TORSO;
  
    double right_x = 0;  
    double right_y = 0;
    double right_z = 0;
  
    double right1_x = 0;  
    double right1_y = 0;
    double right1_z = 0;

    double left_x = 0;  
    double left_y = 0;
    double left_z = 0;

    double left1_x = 0;  
    double left1_y = 0;
    double left1_z = 0;

    double head1_x = 0;  
    double head1_y = 0;
    double head1_z = 0;

float Dist_Head_Neck, Dist_Neck_Torso, Dist_Head_Torso,Dist_Neck_RShoulder,Dist_RShoulder_RElbow,Dist_Neck_RElbow, Dist_RShoulder_RHand,
Dist_RElbow_RHand,Dist_Neck_LShoulder,Dist_LShoulder_LElbow,Dist_Neck_LElbow,Dist_LShoulder_RElbow,Dist_LElbow_LHand,Dist_LShoulder_LHand,
Angle_Head_Neck_Torso,Angle_Neck_RShoulder_RElbow,Angle_RShoulder_RElbow_RHand,Angle_Neck_LShoulder_LElbow,Angle_LShoulder_LElbow_LHand;

float AVG_RH_X, AVG_RH_Y, AVG_RH_Z , cov_RH_LH_X,cov_RH_LH_Y,cov_RH_LH_Z,  cov_RH_H_X,cov_RH_H_Y,cov_RH_H_Z,
      AVG_LH_X, AVG_LH_Y, AVG_LH_Z,  cov_RH_LS_X,cov_RH_LS_Y,cov_RH_LS_Z,  cov_RH_RS_X,cov_RH_RS_Y,cov_RH_RS_Z,
      AVG_RE_X, AVG_RE_Y, AVG_RE_Z,  cov_RH_RE_X,cov_RH_RE_Y,cov_RH_RE_Z,  cov_RH_LE_X,cov_RH_LE_Y,cov_RH_LE_Z,
      AVG_LE_X, AVG_LE_Y, AVG_LE_Z,  cov_RE_RS_X,cov_RE_RS_Y,cov_RE_RS_Z,  cov_RE_LS_X,cov_RE_LS_Y,cov_RE_LS_Z,
      AVG_RS_X, AVG_RS_Y, AVG_RS_Z,  cov_RE_H_X,cov_RE_H_Y,cov_RE_H_Z,     cov_RE_LE_X,cov_RE_LE_Y,cov_RE_LE_Z,
      AVG_LS_X, AVG_LS_Y, AVG_LS_Z,  cov_RE_LH_X,cov_RE_LH_Y,cov_RE_LH_Z,  cov_H_LS_X,cov_H_LS_Y,cov_H_LS_Z,
      AVG_H_X,  AVG_H_Y,  AVG_H_Z,   cov_RS_LS_X,cov_RS_LS_Y,cov_RS_LS_Z,  cov_RS_H_X,cov_RS_H_Y,cov_RS_H_Z,
      AVG_N_X,  AVG_N_Y,  AVG_N_Z ,  cov_RS_LH_X,cov_RS_LH_Y,cov_RS_LH_Z,  cov_RS_LE_X,cov_RS_LE_Y,cov_RS_LE_Z,
   cov_H_LH_X,cov_H_LH_Y,cov_H_LH_Z,   cov_H_LE_X,cov_H_LE_Y,cov_H_LE_Z,   cov_LH_LS_X,cov_LH_LS_Y,cov_LH_LS_Z,
   cov_LE_LS_X,cov_LE_LS_Y,cov_LE_LS_Z, cov_LH_LE_X,cov_LH_LE_Y,cov_LH_LE_Z;  

int loop=0;

/*if( remove("STOP.csv") != 0 || remove("Call.csv") != 0 || remove("Yes.csv") != 0|| remove("No.csv") != 0)
    perror( "Error deleting file" );
  else
    puts( "Files successfully deleted" );*/
////////////////////////////////////// Compute orientation///////////////////////////////////////////////

        sub = h2.subscribe("motion",1, &motion_compt);
        
///////////////////////////////////////////////////////////////////////////////////////////////////////
       
	while (node.ok()){ 
                ros::spinOnce();
		tf::StampedTransform tf_right_hand;
		tf::StampedTransform tf_left_hand;
                tf::StampedTransform tf_neck;
                tf::StampedTransform tf_right_elbow;
                tf::StampedTransform tf_left_elbow; 
                tf::StampedTransform tf_left_shoulder; 
                tf::StampedTransform tf_right_shoulder;  
                tf::StampedTransform tf_head;    
		try{    
                         ros::Duration timeout(1.0 / 30);
                         ros::Time now = ros::Time(0);//now();
// ---------- FOR THE distance Neck/torso  ---------------------------------------------------------------
                
                    listener.waitForTransform("/torso_1", "/neck_1", now, ros::Duration(0.3) );
                    listener.lookupTransform("/torso_1","/neck_1", ros::Time(0), tf_neck);
                    double x_neck = tf_neck.getOrigin().x();  // returns a position of the joint with respect to fixed frame 
		    double y_neck = tf_neck.getOrigin().y();  // individual elements of position can be accessed by x,y,z
		    double z_neck = tf_neck.getOrigin().z();
			
                      double roll_neck,pitch_neck, yaw_neck;          // compute temporal rotations
                       tf_neck.getBasis().getRPY(roll_neck,pitch_neck,yaw_neck);
                       tf::Quaternion q_neck=tf_neck.getRotation();

                        neck_roll.push_back(roll_neck);
                        neck_pitch.push_back(pitch_neck);
                        neck_yaw.push_back(yaw_neck);

			neck_x.push_back(x_neck);
			neck_y.push_back(y_neck);
			neck_z.push_back(z_neck);    
			
			cout <<"Neck VALUE PUSHED INTO VECTOR" <<endl;  // cout << '\a';

// ---------- FOR THE distance right_shoulder/torso  ---------------------------------------------------------------
               
                     listener.waitForTransform("/torso_1", "/right_shoulder_1", now, ros::Duration(0.3) );
                    listener.lookupTransform("/torso_1","/right_shoulder_1", ros::Time(0), tf_right_shoulder);
                double x_right_shoulder = tf_right_shoulder.getOrigin().x();  // returns a position of the joint with respect to fixed frame 
		double y_right_shoulder = tf_right_shoulder.getOrigin().y();  // individual elements of position can be accessed by x,y,z
		double z_right_shoulder = tf_right_shoulder.getOrigin().z();
			
                     double roll_right_shoulder,pitch_right_shoulder, yaw_right_shoulder;          // compute temporal rotations
                       tf_right_shoulder.getBasis().getRPY(roll_right_shoulder,pitch_right_shoulder,yaw_right_shoulder);
                       tf::Quaternion q_right_shoulder=tf_right_shoulder.getRotation();

                        right_shoulder_roll.push_back(roll_right_shoulder);
                        right_shoulder_pitch.push_back(pitch_right_shoulder);
                        right_shoulder_yaw.push_back(yaw_right_shoulder);

			right_shoulder_x.push_back(x_right_shoulder);
			right_shoulder_y.push_back(y_right_shoulder);
			right_shoulder_z.push_back(z_right_shoulder);    
			
			cout <<"right_shoulder VALUE PUSHED INTO VECTOR" <<endl;

// ---------- FOR THE distance left_shoulder/torso  ---------------------------------------------------------------
               
                    listener.waitForTransform("/torso_1", "/left_shoulder_1", now, ros::Duration(0.3) );
                    listener.lookupTransform("/torso_1","/left_shoulder_1", ros::Time(0), tf_left_shoulder);
                double x_left_shoulder = tf_left_shoulder.getOrigin().x();  // returns a position of the joint with respect to fixed frame 
		double y_left_shoulder = tf_left_shoulder.getOrigin().y();  // individual elements of position can be accessed by x,y,z
		double z_left_shoulder = tf_left_shoulder.getOrigin().z();
			
                     double roll_left_shoulder,pitch_left_shoulder, yaw_left_shoulder;          // compute temporal rotations
                     tf_left_shoulder.getBasis().getRPY(roll_left_shoulder,pitch_left_shoulder,yaw_left_shoulder);
                     tf::Quaternion q_left_shoulder=tf_left_shoulder.getRotation();

                     left_shoulder_roll.push_back(roll_left_shoulder);
                     left_shoulder_pitch.push_back(pitch_left_shoulder);
                     left_shoulder_yaw.push_back(yaw_left_shoulder);

		     left_shoulder_x.push_back(x_left_shoulder);
		     left_shoulder_y.push_back(y_left_shoulder);
		     left_shoulder_z.push_back(z_left_shoulder);    
			
		     cout <<"left_shoulder VALUE PUSHED INTO VECTOR" <<endl;

// ---------- FOR THE distance RIGHT HAND/torso  ---------------------------------------------------------------
			
			listener.waitForTransform("/torso_1", "/right_hand_1", now, ros::Duration(0.3) ); 
			listener.lookupTransform("/torso_1","/right_hand_1", ros::Time(0), tf_right_hand);

			double x_right_hand = tf_right_hand.getOrigin().x();  // returns a position of the joint with respect to fixed frame 
			double y_right_hand = tf_right_hand.getOrigin().y();  // individual elements of position can be accessed by x,y,z
			double z_right_hand = tf_right_hand.getOrigin().z();
			
			// the difference between current and previous position 
			/*double right_x_diff = right_x_tmp - right_x;
			double right_y_diff = right_y_tmp - right_y;
			double right_z_diff = right_z_tmp - right_z;

			right_x = right_x_tmp;  
			right_y = right_y_tmp;
			right_z = right_z_tmp;*/
                       double roll_right_hand,pitch_right_hand, yaw_right_hand;          // compute temporal rotations
                       tf_right_hand.getBasis().getRPY(roll_right_hand,pitch_right_hand,yaw_right_hand);
                       tf::Quaternion q_right_hand=tf_right_hand.getRotation();

			//putting the values in vector to save
                        right_hand_roll.push_back(roll_right_hand);
                        right_hand_pitch.push_back(pitch_right_hand);
                        right_hand_yaw.push_back(yaw_right_hand);

			right_hand_x.push_back(x_right_hand);
			right_hand_y.push_back(y_right_hand);
			right_hand_z.push_back(z_right_hand);
                 			
			cout <<"RIGHT HAND VALUE PUSHED INTO VECTOR" <<endl;

// --------------------- FOR THE distance right elbow/torso ------------------------------------------------------			
			
		       listener.waitForTransform("/torso_1", "/left_hand_1", now, ros::Duration(0.3) );
                       listener.lookupTransform("/torso_1", "/left_hand_1", ros::Time(0), tf_left_hand);
			
			double x_left_hand = tf_left_hand.getOrigin().x();  // returns a position of the joint with respect to fixed frame 
			double y_left_hand = tf_left_hand.getOrigin().y();  // individual elements of position can be accessed by x,y,z
			double z_left_hand = tf_left_hand.getOrigin().z();

			// the difference between current and previous position 
		/*	double left_x_diff = left_x_tmp - left_x;
			double left_y_diff = left_y_tmp - left_y;
			double left_z_diff = left_z_tmp - left_z;

			left_x = left_x_tmp;  
			left_y = left_y_tmp;
			left_z = left_z_tmp;*/
                       double roll_left_hand,pitch_left_hand, yaw_left_hand;          // compute temporal rotations
                       tf_left_hand.getBasis().getRPY(roll_left_hand,pitch_left_hand,yaw_left_hand);
                       tf::Quaternion q_left_hand=tf_left_hand.getRotation();

                  //putting the values in vector to save
                        left_hand_x.push_back(x_left_hand);
		            	left_hand_y.push_back(y_left_hand);
		            	left_hand_z.push_back(z_left_hand);

                        left_hand_roll.push_back(roll_left_hand);
                        left_hand_pitch.push_back(pitch_left_hand);
                        left_hand_yaw.push_back(yaw_left_hand);

			
		cout <<"LEFT HAND VALUE PUSHED INTO VECTOR" <<endl;	

// --------------------- FOR THE  distance l.elbow/torso------------------------------------------------------			
			
		       listener.waitForTransform("/torso_1", "/right_elbow_1", now, ros::Duration(0.3) );
                       listener.lookupTransform("/torso_1", "/right_elbow_1", ros::Time(0), tf_right_elbow);
			
			double x_right_elbow = tf_right_elbow.getOrigin().x(); //returns a position of the joint with respect to fixed frame 
			double y_right_elbow = tf_right_elbow.getOrigin().y();  // individual elements of position can be accessed by x,y,z
			double z_right_elbow = tf_right_elbow.getOrigin().z();

			// the difference between current and previous position 
			/*double right1_x_diff = right1_x_tmp - right1_x;
			double right1_y_diff = right1_y_tmp - right1_y;
			double right1_z_diff = right1_z_tmp - right1_z;

			right1_x = right1_x_tmp;  
			right1_y = right1_y_tmp;
			right1_z = right1_z_tmp;*/
                       double roll_right_elbow,pitch_right_elbow, yaw_right_elbow;          // compute temporal rotations
                       tf_right_elbow.getBasis().getRPY(roll_right_elbow,pitch_right_elbow,yaw_right_elbow);
                       tf::Quaternion q_right_elbow=tf_right_elbow.getRotation();
    
                      //putting the values in vector to save

			right_elbow_x.push_back(x_right_elbow);
			right_elbow_y.push_back(y_right_elbow);
			right_elbow_z.push_back(z_right_elbow);
               
                       right_elbow_roll.push_back(roll_right_elbow);
                       right_elbow_pitch.push_back(pitch_right_elbow);
                       right_elbow_yaw.push_back(yaw_right_elbow);

			cout <<"Riht Elbow VALUE PUSHED INTO VECTOR" <<endl;


 // --------------------- FOR THE  All joints ------------------------------------------------------			
			
		       listener.waitForTransform("/torso_1", "/left_elbow_1", now, ros::Duration(0.3) );
                       listener.lookupTransform("/torso_1", "/left_elbow_1", ros::Time(0), tf_left_elbow);
			
			double x_left_elbow = tf_left_elbow.getOrigin().x();  // returns a position of the joint with respect to fixed frame 
			double y_left_elbow = tf_left_elbow.getOrigin().y();  // individual elements of position can be accessed by x,y,z
			double z_left_elbow = tf_left_elbow.getOrigin().z();

			// the difference between current and previous position 
			/*double left1_x_diff = left1_x_tmp - left1_x;
			double left1_y_diff = left1_y_tmp - left1_y;
			double left1_z_diff = left1_z_tmp - left1_z;

			left1_x = left1_x_tmp;  
			left1_y = left1_y_tmp;
			left1_z = left1_z_tmp;*/
                       double roll_left_elbow,pitch_left_elbow, yaw_left_elbow;          // compute temporal rotations
                       tf_left_elbow.getBasis().getRPY(roll_left_elbow,pitch_left_elbow,yaw_left_elbow);
                       tf::Quaternion q_left_elbow=tf_left_elbow.getRotation();
                   
                        //putting the values in vector to save

			left_elbow_x.push_back(x_left_elbow);
			left_elbow_y.push_back(y_left_elbow);
			left_elbow_z.push_back(z_left_elbow);

                        left_elbow_roll.push_back(roll_left_elbow);
                        left_elbow_pitch.push_back(pitch_left_elbow);
                        left_elbow_yaw.push_back(yaw_left_elbow);             

			cout <<"LEFT Elbow VALUE PUSHED INTO VECTOR" <<endl;

//////////////////////////////////////////////////////////////////////////////////////////////////////////
		       listener.waitForTransform("/torso_1", "/head_1", now, ros::Duration(0.3) );
                       listener.lookupTransform("/torso_1", "/head_1", ros::Time(0), tf_head);
			
			double x_head =tf_head.getOrigin().x();  // returns a position of the joint with respect to fixed frame 
			double y_head = tf_head.getOrigin().y();  // individual elements of position can be accessed by x,y,z
			double z_head = tf_head.getOrigin().z();

			// the difference between current and previous position 
			/*double head_x_diff = head_x_tmp - head1_x;
			double head_y_diff = head_y_tmp - head1_y;
			double head_z_diff = head_z_tmp - head1_z;

			head1_x = head_x_tmp;  
			head1_y = head_y_tmp;
			head1_z = head_z_tmp;*/

                       double roll_head,pitch_head, yaw_head;          // compute temporal rotations
                       tf_head.getBasis().getRPY(roll_head,pitch_head,yaw_head);
                       tf::Quaternion q_head=tf_head.getRotation();
//putting the values in vector to save

			head_x.push_back(x_head);
			head_y.push_back(y_head);
			head_z.push_back(z_head);

                       head_roll.push_back(roll_head);
                       head_pitch.push_back(pitch_head);
                       head_yaw.push_back(yaw_head);             

			cout <<"HEAD VALUE PUSHED INTO VECTOR" <<endl;

         /********************************************************/
          /**** compute  spacial angles   ************************/

// *********************  Angle head-neck-torso****************************   
    Dist_Head_Neck = sqrt(pow(x_head- x_neck,2)+pow(y_head-y_neck,2)+pow(z_head-z_neck,2)); //distance head-neck   
    Dist_Head_Torso = sqrt(pow(x_head,2)+pow(y_head,2)+pow(z_head,2)); // distance head-torso
    Dist_Neck_Torso = sqrt(pow(x_neck,2)+pow(y_neck,2)+pow(z_neck,2));//distance neck-torso
    Angle_Head_Neck_Torso= acos((pow(Dist_Head_Neck,2)+pow(Dist_Neck_Torso,2)-pow(Dist_Head_Torso,2))/(2* Dist_Head_Neck*Dist_Neck_Torso)); 
    Vec_Angle_Head_Neck_Torso.push_back(Angle_Head_Neck_Torso); 
    cout <<"Angle° head-neck-torso PUSHED INTO VECTOR  " << Angle_Head_Neck_Torso*180/PI <<endl;
   
                  
    // *********************  Angle neck-RShoulder_RElbow****************************   
                 
Dist_Neck_RShoulder = sqrt(pow(x_right_shoulder-x_neck,2)+pow(y_right_shoulder-y_neck,2)+pow(z_right_shoulder-z_neck,2));
Dist_RShoulder_RElbow = sqrt(pow(x_right_shoulder-x_right_elbow,2)+pow(y_right_shoulder-y_right_elbow,2)+pow(z_right_shoulder- z_right_elbow,2)); 
Dist_Neck_RElbow = sqrt(pow(x_right_elbow-x_neck,2)+pow(y_right_elbow-y_neck,2)+pow(z_right_elbow-z_neck,2));             
Angle_Neck_RShoulder_RElbow= acos((pow(Dist_Neck_RShoulder,2)+pow(Dist_RShoulder_RElbow,2)-pow(Dist_Neck_RElbow,2))/(2* Dist_Neck_RShoulder*Dist_RShoulder_RElbow)); 
Vec_Angle_Neck_RShoulder_RElbow.push_back(Angle_Neck_RShoulder_RElbow);
   cout <<"Angle neck-RShoulder_RElbow PUSHED INTO VECTOR  " << Angle_Neck_RShoulder_RElbow*180/PI  <<endl;
 
   // *********************  Angle RShoulder_RElbow_RHand****************************       
Dist_RElbow_RHand= sqrt(pow(x_right_elbow-x_right_hand,2)+pow(y_right_elbow-y_right_hand,2)+pow(z_right_elbow-z_right_hand,2));
Dist_RShoulder_RHand= sqrt(pow(x_right_shoulder-x_right_hand,2)+pow(y_right_shoulder-y_right_hand,2)+pow(z_right_shoulder-z_right_hand,2));
Angle_RShoulder_RElbow_RHand= acos((pow(Dist_RShoulder_RElbow,2)+pow(Dist_RElbow_RHand,2)-pow(Dist_RShoulder_RHand,2))/(2* Dist_RShoulder_RElbow*Dist_RElbow_RHand)); 
Vec_Angle_RShoulder_RElbow_RHand.push_back(Angle_RShoulder_RElbow_RHand);
cout <<"Angle° RShoulder_RElbow_RHand PUSHED INTO VECTOR  " <<  Angle_RShoulder_RElbow_RHand*180/PI <<endl;

 // *********************  Angle neck-LShoulder_LElbow****************************   
Dist_Neck_LShoulder= sqrt(pow(x_neck-x_left_shoulder,2)+pow(y_neck-y_left_shoulder,2)+pow(z_neck-z_left_shoulder,2));
Dist_LShoulder_LElbow= sqrt(pow(x_left_shoulder-x_left_elbow,2)+pow(y_left_shoulder-y_left_elbow,2)+pow(z_left_shoulder-z_left_elbow,2));
Dist_Neck_LElbow= sqrt(pow(x_left_elbow-x_neck,2)+pow(y_left_elbow-y_neck,2)+pow(z_left_elbow-z_neck,2));
Angle_Neck_LShoulder_LElbow= acos((pow(Dist_Neck_LShoulder,2)+pow(Dist_LShoulder_LElbow,2)-pow(Dist_Neck_LElbow,2))/(2*  Dist_Neck_LShoulder*Dist_LShoulder_LElbow)); 
Vec_Angle_Neck_LShoulder_LElbow.push_back(Angle_Neck_LShoulder_LElbow);
cout <<"Angle° neck-LShoulder_LElbow PUSHED INTO VECTOR  " << Angle_Neck_LShoulder_LElbow*180/PI  <<endl;
   
 // *********************  Angle LShoulder_LElbow_LHand****************************       
Dist_LShoulder_LElbow= sqrt(pow(x_left_shoulder-x_left_elbow,2)+pow(y_left_shoulder-y_left_elbow,2)+pow(z_left_shoulder-z_left_elbow,2));
Dist_LElbow_LHand= sqrt(pow(x_left_elbow-x_left_hand,2)+pow(y_left_elbow-y_left_hand,2)+pow(z_left_elbow-z_left_hand,2));
Dist_LShoulder_LHand= sqrt(pow(x_left_shoulder-x_left_hand,2)+pow(y_left_shoulder-y_left_hand,2)+pow(z_left_shoulder-z_left_hand,2));
Angle_LShoulder_LElbow_LHand= acos((pow(Dist_LShoulder_LElbow,2)+pow(Dist_LElbow_LHand,2)-pow(Dist_LShoulder_LHand,2))/(2* Dist_LShoulder_LElbow*Dist_LElbow_LHand)); 
Vec_Angle_LShoulder_LElbow_LHand.push_back(Angle_LShoulder_LElbow_LHand);
 cout <<"Angle° LShoulder_LElbow_LHand PUSHED INTO VECTOR  " << Angle_LShoulder_LElbow_LHand*180/PI <<endl;

		}//try
		catch (tf::TransformException ex){
			ROS_ERROR("%s",ex.what());
		}
		// rate.sleep();
          ros::Duration(1).sleep(); //0.5 second;
        cout<<"frame  "<<loop<<endl;
        loop++;
	}//while ros

// --------------------- FOR THE  distance elbow/shouder------------------------------------------------------	

    //   listener.lookupTransform("/torso_1", "/openni_depth_frame", ros::Time(0), transform3);
//double euler_z =  (atan2(2.0 * (qx*qy + qz*qw),(sqx - sqy - sqz + sqw)) * (180.0f/PI));


    cout <<"ITERATOR STARS NOW, PLEASE PAY ATTENTION\n"<<endl;
    ofstream x_file;
    vector<double>::iterator iy = right_hand_y.begin();      vector<double>::iterator iz = right_hand_z.begin();  
    vector<double>::iterator ir = right_hand_roll.begin();   vector<double>::iterator ip = right_hand_pitch.begin();
    vector<double>::iterator iw = right_hand_yaw.begin(); 
   
    vector<double>::iterator jx = left_hand_x.begin();    vector<double>::iterator jr = left_hand_roll.begin();
    vector<double>::iterator jy = left_hand_y.begin();    vector<double>::iterator jp = left_hand_pitch.begin();
    vector<double>::iterator jz = left_hand_z.begin();    vector<double>::iterator jw = left_hand_yaw.begin();

    vector<double>::iterator kx = right_elbow_x.begin();  vector<double>::iterator kr = right_elbow_roll.begin();
    vector<double>::iterator ky = right_elbow_y.begin();  vector<double>::iterator kp = right_elbow_pitch.begin();
    vector<double>::iterator kz = right_elbow_z.begin();  vector<double>::iterator kw = right_elbow_yaw.begin();

    vector<double>::iterator lx = left_elbow_x.begin();   vector<double>::iterator lr = left_elbow_roll.begin();
    vector<double>::iterator ly = left_elbow_y.begin();   vector<double>::iterator lp = left_elbow_pitch.begin();
    vector<double>::iterator lz = left_elbow_z.begin();   vector<double>::iterator lw = left_elbow_yaw.begin();
    
    vector<double>::iterator mx = head_x.begin();    vector<double>::iterator mr = head_roll.begin();
    vector<double>::iterator my = head_y.begin();    vector<double>::iterator mp = head_pitch.begin();
    vector<double>::iterator mz = head_z.begin();    vector<double>::iterator mw = head_yaw.begin();

    vector<double>::iterator nx = neck_x.begin();    vector<double>::iterator nr = neck_roll.begin();
    vector<double>::iterator ny = neck_y.begin();    vector<double>::iterator np = neck_pitch.begin();
    vector<double>::iterator nz = neck_z.begin();    vector<double>::iterator nw = neck_yaw.begin();

    vector<double>::iterator px = left_shoulder_x.begin();   vector<double>::iterator pr = left_shoulder_roll.begin();
    vector<double>::iterator py = left_shoulder_y.begin();   vector<double>::iterator pp = left_shoulder_pitch.begin();
    vector<double>::iterator pz = left_shoulder_z.begin();   vector<double>::iterator pw = left_shoulder_yaw.begin();
 
    vector<double>::iterator qx = right_shoulder_x.begin();  vector<double>::iterator qr = right_shoulder_roll.begin();
    vector<double>::iterator qy = right_shoulder_y.begin();  vector<double>::iterator qp = right_shoulder_pitch.begin();
    vector<double>::iterator qz = right_shoulder_z.begin();  vector<double>::iterator qw = right_shoulder_yaw.begin();

     vector<double>::iterator teta1 = Vec_Angle_Head_Neck_Torso.begin(); 
     vector<double>::iterator teta2 = Vec_Angle_RShoulder_RElbow_RHand.begin();
     vector<double>::iterator teta3 = Vec_Angle_Neck_RShoulder_RElbow.begin();
     vector<double>::iterator teta4 = Vec_Angle_Neck_LShoulder_LElbow.begin();
     vector<double>::iterator teta5 = Vec_Angle_LShoulder_LElbow_LHand.begin();
   

    vector<double>::iterator r = motion_vect.begin();
   /* vector<double>::iterator s = pose_y.begin();
    vector<double>::iterator t = pose_z.begin();*/

if(strcmp(argv[1],"Stop")==0) 
   { x_file.open ("Stop_Orien.csv", ios::app); //the flag ios::app makes sure that the control starts at the end of already existing file.
		x_file << 1;
		x_file << ",";
   }

 if(strcmp(argv[1],"Call")==0) 
   { x_file.open ("Call_Orien.csv", ios::app); //the flag ios::app makes sure that the control starts at the end of already existing file.
		x_file << 2;
		x_file << ",";
	}


if(strcmp(argv[1],"No")==0) 
   { x_file.open ("No_Orien.csv", ios::app); //the flag ios::app makes sure that the control starts at the end of already existing file.
		x_file << 3;
		x_file << ",";
	}
if(strcmp(argv[1],"Yes")==0) 
   { x_file.open ("Yes_Orien.csv", ios::app); //the flag ios::app makes sure that the control starts at the end of already existing file.
		x_file << 4;
	    x_file << ",";
	}
 
 float    min_ix, min_iy, min_iz,    max_ix, max_iy, max_iz, 
          min_jx, min_jy, min_jz,    max_jx, max_jy, max_jz,
          min_kx, min_ky, min_kz,    max_kx, max_ky, max_kz,
          min_lx, min_ly, min_lz,    max_lx, max_ly, max_lz,
          min_mx, min_my, min_mz,    max_mx, max_my, max_mz,
          min_nx, min_ny, min_nz,    max_nx, max_ny, max_nz,
          min_px, min_py, min_pz,    max_px, max_py, max_pz,
          min_qx, min_qy, min_qz,    max_qx, max_qy, max_qz;

 max_ix=min_ix= *right_hand_x.begin();      max_iy=min_iy = *right_hand_y.begin();     max_iz=min_iz = *right_hand_z.begin();  
 max_jx=min_jx =*left_hand_x.begin();       max_jy=min_jy = *left_hand_y.begin();      max_jz=min_jz = *left_hand_z.begin();  
 max_kx=min_kx =*right_elbow_x.begin();     max_ky=min_ky = *right_elbow_y.begin();    max_kz=min_kz = *right_elbow_z.begin(); 
 max_lx=min_lx = *left_elbow_x.begin();     max_ly=min_ly = *left_elbow_y.begin();     max_lz=min_lz = *left_elbow_z.begin();
 max_px=min_px = *left_shoulder_x.begin();  max_py=min_py = *left_shoulder_y.begin();  max_pz=min_pz = *left_shoulder_z.begin(); 
 max_qx=min_qx = *right_shoulder_x.begin(); max_qy=min_qy = *right_shoulder_y.begin(); max_qz=min_qz = *right_shoulder_z.begin();
 max_mx=min_mx = *head_x.begin();           max_my=min_my = *head_y.begin();           max_mz=min_mz = *head_z.begin();
 max_nx=min_nx = *neck_x.begin();           max_ny=min_ny = *neck_y.begin();           max_nz=min_nz = *neck_z.begin(); 
 

  // ************************* Features pre-processing ************************************************
 
   for (vector<double>::iterator ix = right_hand_x.begin(); ix!= right_hand_x.begin()+taille;++ix){
    
    // compute somme 
     AVG_RH_X=AVG_RH_X+*ix;     AVG_LH_X=AVG_LH_X+*jx;   
     AVG_RH_Y=AVG_RH_Y+*iy;     AVG_LH_Y=AVG_LH_Y+*jy;
     AVG_RH_Z=AVG_RH_Z+*iz;     AVG_LH_Z=AVG_LH_Z+*jy;
 
     AVG_RE_X=AVG_RE_X+*kx;     AVG_LE_X=AVG_LE_X+*lx;   
     AVG_RE_Y=AVG_RE_Y+*ky;     AVG_LE_Y=AVG_LE_Y+*ly;
     AVG_RE_Z=AVG_RE_Z+*kz;     AVG_LE_Z=AVG_LE_Z+*ly;

     AVG_RS_X=AVG_RS_X+*qx;     AVG_LS_X=AVG_LS_X+*px;   
     AVG_RS_Y=AVG_RS_Y+*qy;     AVG_LS_Y=AVG_LS_Y+*py;
     AVG_RS_Z=AVG_RS_Z+*qz;     AVG_LS_Z=AVG_LS_Z+*py;

     AVG_H_X=AVG_H_X+*mx;     AVG_N_X=AVG_N_X+*nx;   
     AVG_H_Y=AVG_H_Y+*my;     AVG_N_Y=AVG_N_Y+*ny;
     AVG_H_Z=AVG_H_Z+*mz;     AVG_N_Z=AVG_N_Z+*ny;


       ///************   Smoothing values**********************************
     /* *ix=(*ix+*(ix+1)+*(ix+2))/3;       *jx=(*jx+*(jx+1)+*(jx+2))/3;
      *iy=(*iy+*(iy+1)+*(iy+2))/3;       *jy=(*iy+*(jy+1)+*(jy+2))/3;
      *iz=(*iz+*(iz+1)+*(iz+2))/3;       *jz=(*iz+*(jz+1)+*(jz+2))/3;      

      *kx=(*kx+*(kx+1)+*(kx+2))/3;       *lx=(*lx+*(lx+1)+*(lx+2))/3;
      *kz=(*kz+*(kz+1)+*(kz+2))/3;       *ly=(*ly+*(ly+1)+*(ly+2))/3; 
      *ky=(*ky+*(ky+1)+*(ky+2))/3;       *lz=(*lz+*(lz+1)+*(lz+2))/3;
     
      *mx=(*mx+*(mx+1)+*(mx+2))/3;       *nx=(*nx+*(nx+1)+*(nx+2))/3;
      *mz=(*mz+*(mz+1)+*(mz+2))/3;       *ny=(*ny+*(ny+1)+*(ny+2))/3; 
      *my=(*my+*(my+1)+*(my+2))/3;       *nz=(*nz+*(nz+1)+*(nz+2))/3;

      *px=(*px+*(px+1)+*(px+2))/3;       *qx=(*qx+*(qx+1)+*(qx+2))/3;
      *pz=(*pz+*(pz+1)+*(pz+2))/3;       *qy=(*qy+*(qy+1)+*(qy+2))/3; 
      *py=(*py+*(py+1)+*(py+2))/3;       *qz=(*qz+*(qz+1)+*(qz+2))/3;*/

//******************************** Normalisation ***************************
  if (*ix<min_ix) min_ix=*ix;      if (*ix>max_ix) max_ix=*ix;        // cout<<"RH_x  " << min_ix  << "  ---  "<<  max_ix  <<endl;
  if (*iy<min_iy) min_iy=*iy;      if (*iy>max_iy) max_iy=*iy;  iy++;  ///cout<<"RH_y  " <<min_iy  << "  ---  "<<  max_iy  <<endl;
  if (*iz<min_iz) min_iz=*iz;      if (*iz>max_iz) max_iz=*iz;  iz++;  //cout<< "RH_z "<<min_iz  << "  ---  "<<  max_iz  <<endl;

  if (*jx<min_jx) min_jx=*jx;      if (*jx>max_jx) max_jx=*jx;  jx++;
  if (*jy<min_jy) min_jy=*jy;      if (*jy>max_jy) max_jy=*jy;  jy++;
  if (*jz<min_jz) min_jz=*jz;      if (*jz>max_jz) max_jz=*jz;  jz++;

  if (*kx<min_kx) min_kx=*kx;      if (*kx>max_kx) max_kx=*kx;  kx++;
  if (*ky<min_ky) min_ky=*ky;      if (*ky>max_ky) max_ky=*ky;  ky++;
  if (*kz<min_kz) min_kz=*kz;      if (*kz>max_kz) max_kz=*kz;  kz++;

  if (*lx<min_lx) min_lx=*lx;      if (*lx>max_lx) max_lx=*lx;  lx++;
  if (*ly<min_ly) min_ly=*ly;      if (*ly>max_ly) max_ly=*ly;  ly++;
  if (*lz<min_lz) min_lz=*lz;      if (*lz>max_lz) max_lz=*lz;  lz++;

  if (*mx<min_mx) min_mx=*mx;      if (*mx>max_mx) max_mx=*mx;  mx++;
  if (*my<min_my) min_my=*my;      if (*my>max_my) max_my=*my;  my++;
  if (*mz<min_mz) min_mz=*mz;      if (*mz>max_mz) max_mz=*mz;  mz++;
 
 if (*nx<min_nx) min_nx=*nx;      if (*nx>max_nx) max_nx=*nx;  nx++;
 if (*ny<min_ny) min_ny=*ny;      if (*ny>max_ny) max_ny=*ny;  ny++;
 if (*nz<min_nz) min_nz=*nz;      if (*nz>max_nz) max_nz=*nz;  nz++;

 if (*px<min_px) min_px=*px;      if (*px>max_px) max_px=*px;  px++;
 if (*py<min_py) min_py=*py;      if (*py>max_py) max_py=*py;  py++;
 if (*pz<min_pz) min_pz=*pz;      if (*pz>max_pz) max_pz=*pz;  pz++;

 if (*qx<min_qx) min_qx=*qx;      if (*qx>max_qx) max_qx=*qx;  qx++;
 if (*qy<min_qy) min_qy=*qy;      if (*qy>max_qy) max_qy=*qy;  qy++;
 if (*qz<min_qz) min_qz=*qz;      if (*qz>max_qz) max_qz=*qz;  qz++;

//**************************************************************************

}
      // compute Averge

     AVG_RH_X=AVG_RH_X/taille;    //x_file <<  AVG_RH_X;  
     AVG_RH_Y=AVG_RH_Y/taille;    //x_file <<  AVG_RH_Y;
     AVG_RH_Z=AVG_RH_Z/taille;    //x_file <<  AVG_RH_Z; 

     AVG_LH_X=AVG_LH_X/taille;    //x_file <<  AVG_LH_X;
     AVG_LH_Y=AVG_LH_Y/taille;    // x_file <<  AVG_LH_Y;
     AVG_LH_Z=AVG_LH_Z/taille;    //x_file <<  AVG_LH_Z;
     
     AVG_RE_X=AVG_RE_X/taille;    //x_file <<  AVG_RE_X;
     AVG_RE_Y=AVG_RE_Y/taille;    //x_file <<  AVG_RE_Y;
     AVG_RE_Z=AVG_RE_Z/taille;    //x_file <<  AVG_RE_Z;

     AVG_LE_X=AVG_LE_X/taille;    //x_file <<  AVG_LE_X;
     AVG_LE_Y=AVG_LE_Y/taille;    //x_file <<  AVG_LE_Y;
     AVG_LE_Z=AVG_LE_Z/taille;    //x_file <<  AVG_LE_Z;
     
     AVG_H_X=AVG_H_X/taille;    //x_file <<  AVG_H_X;
     AVG_H_Y=AVG_H_Y/taille;    //x_file <<  AVG_H_Y;
     AVG_H_Z=AVG_H_Z/taille;    //x_file <<  AVG_H_Z;

     AVG_N_X=AVG_N_X/taille;    
     AVG_N_Y=AVG_N_Y/taille;    
     AVG_N_Z=AVG_N_Z/taille;

     AVG_RS_X=AVG_RS_X/taille;    //x_file <<  AVG_RE_X;
     AVG_RS_Y=AVG_RS_Y/taille;    //x_file <<  AVG_RE_Y;
     AVG_RS_Z=AVG_RS_Z/taille;    //x_file <<  AVG_RE_Z;

     AVG_LS_X=AVG_LS_X/taille;    //x_file <<  AVG_LE_X;
     AVG_LS_Y=AVG_LS_Y/taille;    //x_file <<  AVG_LE_Y;
     AVG_LS_Z=AVG_LS_Z/taille;



//float epsilon=0.001;
   
   for (vector<double>::iterator ix = right_hand_x.begin(); ix!= right_hand_x.begin()+taille;++ix){
		
    // Distance % torso 
         			 
       /*    if(max_ix!=min_ix)  *ix=(*ix-min_ix)/(max_ix-min_ix);
           if(max_iy!=min_iy)  *iy=(*iy-min_iy)/(max_iy-min_iy);
           if(max_iz!=min_iz)  *iz=(*iz-min_iz)/(max_iz-min_iz);*/
           // x_file << ",";
           // x_file<< *ix;               
                                       // compute covariance RH
     cov_RH_RS_X=cov_RH_RS_X+(*ix-AVG_RH_X)*(*qx-AVG_RS_X);  // x_file << cov_RH_RS_X;    x_file << ","; 
     cov_RH_RS_Y=cov_RH_RS_Y+(*iy-AVG_RH_Y)*(*qy-AVG_RS_Y);  // x_file << cov_RH_RS_Y;    x_file << ","; 
     cov_RH_RS_Z=cov_RH_RS_Z+(*iz-AVG_RH_Z)*(*qz-AVG_RS_Z);  //  x_file << cov_RH_RS_Z;    x_file << ","; 

     cov_RH_LS_X=cov_RH_LS_X+(*ix-AVG_RH_X)*(*px-AVG_LS_X);  //  x_file << cov_RH_LS_X;   x_file << ","; 
     cov_RH_LS_Y=cov_RH_LS_Y+(*iy-AVG_RH_Y)*(*py-AVG_LS_Y);  // x_file << cov_RH_LS_Y;   x_file << ","; 
     cov_RH_LS_Z=cov_RH_LS_Z+(*iz-AVG_RH_Z)*(*pz-AVG_LS_Z);  //  x_file << cov_RH_LS_Z;   x_file << ","; 

     cov_RH_RE_X=cov_RH_RE_X+(*ix-AVG_RH_X)*(*kx-AVG_RE_X);  //  x_file << cov_RH_RE_X;   x_file << ","; 
     cov_RH_RE_Y=cov_RH_RE_Y+(*iy-AVG_RH_Y)*(*ky-AVG_RE_Y);  // x_file << cov_RH_RE_Y;   x_file << ","; 
     cov_RH_RE_Z=cov_RH_RE_Z+(*iz-AVG_RH_Z)*(*kz-AVG_RE_Z);  //  x_file << cov_RH_RE_Z;   x_file << ","; 
           
     cov_RH_LE_X=cov_RH_LE_X+(*ix-AVG_RH_X)*(*lx-AVG_LE_X);   // x_file << cov_RH_LE_X;   x_file << ",";  
     cov_RH_LE_Y=cov_RH_LE_Y+(*iy-AVG_RH_Y)*(*ly-AVG_LE_Y);   // x_file << cov_RH_LE_Y;   x_file << ","; 
     cov_RH_LE_Z=cov_RH_LE_Z+(*iz-AVG_RH_Z)*(*lz-AVG_LE_Z);   //x_file << cov_RH_LE_Z;   x_file << ","; 
   
     cov_RH_H_X=cov_RH_H_X+(*ix-AVG_RH_X)*(*mx-AVG_H_X);      // x_file << cov_RH_H_X;   x_file << ","; 
     cov_RH_H_Y=cov_RH_H_Y+(*iy-AVG_RH_Y)*(*my-AVG_H_Y);      // x_file << cov_RH_H_Y;   x_file << ","; 
     cov_RH_H_Z=cov_RH_H_Z+(*iz-AVG_RH_Z)*(*mz-AVG_H_Z);      // x_file << cov_RH_H_Z;   x_file << ","; 
    
     cov_RH_LH_X=cov_RH_LH_X+(*ix-AVG_RH_X)*(*jx-AVG_LH_X);    x_file << cov_RH_LH_X;   x_file << ","; 
     cov_RH_LH_Y=cov_RH_LH_Y+(*iy-AVG_RH_Y)*(*iy-AVG_LH_Y);    x_file << cov_RH_LH_Y;   x_file << ","; 
     cov_RH_LH_Z=cov_RH_LH_Z+(*iz-AVG_RH_Z)*(*jz-AVG_LH_Z);    x_file << cov_RH_LH_Z;   x_file << ","; 

    
      // compute covariance  RE  
          /* cov_RE_LH_X= cov_RE_LH_X+(*kx-AVG_RE_X)*(*jx-AVG_LH_X);   x_file << cov_RE_LH_X;    x_file << ","; 
           cov_RE_LH_Y= cov_RE_LH_Y+(*ky-AVG_RE_Y)*(*jy-AVG_LH_Y);   x_file << cov_RE_LH_Y;    x_file << ","; 
           cov_RE_LH_Z= cov_RE_LH_Z+(*kz-AVG_RE_Z)*(*jz-AVG_LH_Z);   x_file << cov_RE_LH_Z;    x_file << ",";  
  
           cov_RE_LE_X=cov_RE_LE_X+(*kx-AVG_RE_X)*(*lx-AVG_LE_X);    x_file << cov_RE_LE_X;    x_file << ","; 
           cov_RE_LE_Y=cov_RE_LE_Y+(*ky-AVG_RE_Y)*(*ly-AVG_LE_Y);    x_file << cov_RE_LE_Y;    x_file << ","; 
           cov_RE_LE_Z=cov_RE_LE_Z+(*kz-AVG_RE_Z)*(*lz-AVG_LE_Z);    x_file << cov_RE_LE_Z;    x_file << ",";	

           cov_RE_RS_X=cov_RE_RS_X+(*kx-AVG_RE_X)*(*qx-AVG_RS_X);    x_file << cov_RE_RS_X;    x_file << ","; 
           cov_RE_RS_Y=cov_RE_RS_Y+(*ky-AVG_RE_Y)*(*qy-AVG_RS_Y);    x_file << cov_RE_RS_Y;    x_file << ","; 
           cov_RE_RS_Z= cov_RE_RS_Z+(*kz-AVG_RE_Z)*(*qz-AVG_RS_Z);   x_file << cov_RE_RS_Z;    x_file << ","; 

           cov_RE_H_X=cov_RE_H_X+(*kx-AVG_RE_X)*(*mx-AVG_H_X);    x_file << cov_RE_H_X;    x_file << ","; 
           cov_RE_H_Y=cov_RE_H_Y+(*ky-AVG_RE_Y)*(*my-AVG_H_Y);    x_file << cov_RE_H_Y;    x_file << ","; 
           cov_RE_H_Z= cov_RE_H_Z+(*kz-AVG_RE_Z)*(*mz-AVG_H_Z);    x_file << cov_RE_H_Z;    x_file << ","; 

           cov_RE_LS_X=cov_RE_LS_X+(*kx-AVG_RE_X)*(*px-AVG_LS_X);    x_file << cov_RE_LS_X;    x_file << ","; 
           cov_RE_LS_Y=cov_RE_LS_Y+(*ky-AVG_RE_Y)*(*py-AVG_LS_Y);    x_file << cov_RE_LS_Y;    x_file << ","; 
           cov_RE_LS_Z=cov_RE_LS_Z+(*kz-AVG_RE_Z)*(*pz-AVG_LS_Z);    x_file << cov_RE_LS_Z;    x_file << ",";	

   // compute covariance  RS
   cov_RS_H_X=cov_RS_H_X+(*qx-AVG_RS_X)*(*mx-AVG_H_X);    x_file << cov_RS_H_X;    x_file << ","; 
   cov_RS_H_Y=cov_RS_H_Y+(*qy-AVG_RS_Y)*(*my-AVG_H_Y);    x_file << cov_RS_H_Y;    x_file << ","; 
   cov_RS_H_Z= cov_RS_H_Z+(*qz-AVG_RS_Z)*(*mz-AVG_H_Z);   x_file << cov_RS_H_Z;    x_file << ","; 

   cov_RS_LH_X=cov_RS_LH_X+(*qx-AVG_RS_X)*(*jx-AVG_LH_X);    x_file << cov_RS_LH_X;    x_file << ","; 
   cov_RS_LH_Y=cov_RS_LH_Y+(*qy-AVG_RS_Y)*(*jy-AVG_LH_Y);    x_file << cov_RS_LH_Y;    x_file << ","; 
   cov_RS_LH_Z= cov_RS_LH_Z+(*qz-AVG_RS_Z)*(*jz-AVG_LH_Z);   x_file << cov_RS_LH_Z;    x_file << ","; 

   cov_RS_LE_X=cov_RS_LE_X+(*qx-AVG_RS_X)*(*lx-AVG_LE_X);    x_file << cov_RS_LE_X;    x_file << ","; 
   cov_RS_LE_Y=cov_RS_LE_Y+(*qy-AVG_RS_Y)*(*ly-AVG_LE_Y);    x_file << cov_RS_LE_Y;    x_file << ","; 
   cov_RS_LE_Z= cov_RS_LE_Z+(*qz-AVG_RS_Z)*(*lz-AVG_LE_Z);   x_file << cov_RS_LE_Z;    x_file << ","; 

   cov_RS_LS_X=cov_RS_LS_X+(*qx-AVG_RS_X)*(*px-AVG_LS_X);    x_file << cov_RS_LS_X;    x_file << ","; 
   cov_RS_LS_Y=cov_RS_LS_Y+(*qy-AVG_RS_Y)*(*py-AVG_LS_Y);    x_file << cov_RS_LS_Y;    x_file << ","; 
   cov_RS_LS_Z= cov_RS_LS_Z+(*qz-AVG_RS_Z)*(*pz-AVG_LS_Z);   x_file << cov_RS_LS_Z;    x_file << ","; 

 // compute covariance  H
   cov_H_LH_X=cov_H_LH_X+(*mx-AVG_H_X)*(*jx-AVG_LH_X);    x_file << cov_H_LH_X;    x_file << ","; 
   cov_H_LH_Y=cov_H_LH_Y+(*my-AVG_H_Y)*(*jy-AVG_LH_Y);    x_file << cov_H_LH_Y;    x_file << ","; 
   cov_H_LH_Z= cov_H_LH_Z+(*mz-AVG_H_Z)*(*jz-AVG_LH_Z);   x_file << cov_H_LH_Z;    x_file << ","; 

   cov_H_LE_X=cov_H_LE_X+(*mx-AVG_H_X)*(*lx-AVG_LE_X);    x_file << cov_H_LE_X;    x_file << ","; 
   cov_H_LE_Y=cov_H_LE_Y+(*my-AVG_H_Y)*(*ly-AVG_LE_Y);    x_file << cov_H_LE_Y;    x_file << ","; 
   cov_H_LE_Z= cov_H_LE_Z+(*mz-AVG_H_Z)*(*lz-AVG_LE_Z);   x_file << cov_H_LE_Z;    x_file << ","; 

   cov_H_LS_X=cov_H_LS_X+(*mx-AVG_H_X)*(*px-AVG_LS_X);    x_file << cov_H_LS_X;    x_file << ","; 
   cov_H_LS_Y=cov_H_LS_Y+(*my-AVG_H_Y)*(*py-AVG_LS_Y);    x_file << cov_H_LS_Y;    x_file << ","; 
   cov_H_LS_Z= cov_H_LS_Z+(*mz-AVG_H_Z)*(*pz-AVG_LS_Z);   x_file << cov_H_LS_Z;    x_file << ","; 

   // compute covariance  LH
   cov_LH_LE_X=cov_LH_LE_X+(*jx-AVG_LH_X)*(*lx-AVG_LE_X);    x_file << cov_LH_LE_X;    x_file << ","; 
   cov_LH_LE_Y=cov_LH_LE_Y+(*jy-AVG_LH_Y)*(*ly-AVG_LE_Y);    x_file << cov_LH_LE_Y;    x_file << ","; 
   cov_LH_LE_Z= cov_LH_LE_Z+(*jz-AVG_LH_Z)*(*lz-AVG_LE_Z);   x_file << cov_LH_LE_Z;    x_file << ","; 
 
   cov_LH_LS_X=cov_LH_LS_X+(*jx-AVG_LH_X)*(*px-AVG_LS_X);    x_file << cov_LH_LS_X;    x_file << ","; 
   cov_LH_LS_Y=cov_LH_LS_Y+(*jy-AVG_LH_Y)*(*py-AVG_LS_Y);    x_file << cov_LH_LS_Y;    x_file << ","; 
   cov_LH_LS_Z= cov_LH_LS_Z+(*jz-AVG_LH_Z)*(*pz-AVG_LS_Z);   x_file << cov_LH_LS_Z;    x_file << ","; 

 // compute covariance  LE
   cov_LE_LS_X=cov_LE_LS_X+(*lx-AVG_LE_X)*(*px-AVG_LS_X);    x_file << cov_LE_LS_X;    x_file << ","; 
   cov_LE_LS_Y=cov_LE_LS_Y+(*ly-AVG_LE_Y)*(*py-AVG_LS_Y);    x_file << cov_LE_LS_Y;    x_file << ","; 
   cov_LE_LS_Z= cov_LE_LS_Z+(*lz-AVG_LE_Z)*(*pz-AVG_LS_Z);   x_file << cov_LE_LS_Z;    x_file << ","; */

	      /*  x_file<< *iy;
	        x_file << ",";     
            iy++;*/
      
          
           /* x_file<< *iz;    
            x_file << ",";
            iz++;*/
             
             /// temporal rotations
            x_file<< *ir;   
            x_file << ",";
            ir++;

           x_file<< *ip;   
            x_file << ",";
            ip++;

           x_file<< *iw;   
            x_file << ",";
            iw++;

                       ///// right hand///////
      
                      /// Velocity total
          /*  x_file<< sqrt(pow(*ix-*(ix+1),2)+ pow(*iy-*(iy+1),2)+ pow(*iz-*(iz+1),2))/frame_rate; 
            x_file << ","; */
           
                     /// Velocity of each direction 
          /*  x_file<< (*ix-*(ix+1))/frame_rate; x_file << ",";
            x_file<< (*iy-*(iy+1))/frame_rate; x_file << ",";       
            x_file<< (*iz-*(iz+1))/frame_rate; x_file << ","; */
                
                   /// distance in each direction 
          /*   x_file<< *ix-*(ix+1);  x_file << ",";
             x_file<< *iy-*(iy+1);  x_file << ",";
             x_file<< *iz-*(iz+1);  x_file << ",";*/

          //  iy++;   iz++;

/////////////////////// Right elbow//////////////

          /* if(max_kx!=min_kx)  *kx=(*kx-min_kx)/(max_kx-min_kx);
           if(max_ky!=min_ky)  *ky=(*ky-min_ky)/(max_ky-min_ky);
           if(max_kz!=min_kz)  *kz=(*kz-min_kz)/(max_kz-min_kz);*/
		
           

           /*  x_file<< *kx;
             x_file << ",";
             kx++;*/

             //x_file << ",";
          /*   x_file<< *ky;        	             
             x_file << ",";
             ky++;*/

            // x_file << ",";	
            /* x_file<< *kz;                 
             x_file << ",";
             kz++;*/

           /// temporal rotations
            x_file<< *kr;   
            x_file << ",";
            kr++;

            x_file<< *kp;   
            x_file << ",";
            kp++;

            x_file<< *kw;   
            x_file << ",";
            kw++;

         /// Velocity total
         //   x_file<< sqrt(pow(*kx-*(kx+1),2)+ pow(*ky-*(ky+1),2)+pow(*kz-*(kz+1),2))/frame_rate;  x_file << ",";

         /// Velocity of each direction 
           /* x_file<< (*kx-*(kx+1))/frame_rate; x_file << ",";
            x_file<< (*ky-*(ky+1))/frame_rate; x_file << ",";
            x_file<< (*kz-*(kz+1))/frame_rate; x_file << ",";*/

          /// distance in each direction 
         /*     x_file<< *kx-*(kx+1);  x_file << ","; 
              x_file<< *ky-*(ky+1);  x_file << ",";
              x_file<< *kz-*(kz+1);  x_file << ","; */

      //  kx++;   ky++;       kz++;
     ///////////// Left hand///////////////////
    
	/*  if(max_jx!=min_jx)  *ix=(*jx-min_jx)/(max_jx-min_jx);
           if(max_jy!=min_jy)  *iy=(*jy-min_jy)/(max_jy-min_jy);
           if(max_jz!=min_jz)  *iz=(*jz-min_jz)/(max_jz-min_jz);*/

           // x_file << ",";	
           /* x_file<< *jx;
            x_file << ",";
	        jx++;*/

           // x_file << ",";
          /*  x_file<< *jy;
            x_file << ",";       
            jy++;*/
      
           // x_file << ",";
          /*  x_file<< *jz;   
            x_file << ",";  
            jz++;*/

           /// temporal rotations
           x_file<< *jr;   
            x_file << ",";
            jr++;

            x_file<< *jp;   
            x_file << ",";
            jp++;

            x_file<< *jw;   
            x_file << ",";
            jw++;
                              /// Velocity total
      //      x_file<< sqrt(pow(*jx-*(jx+1),2)+ pow(*jy-*(jy+1),2)+ pow(*jz-*(jz+1),2))/frame_rate;  x_file << ",";
                       
        /*                  /// Velocity of each direction 
            x_file<< (*jx-*(jx+1))/frame_rate; x_file << ",";
            x_file<< (*jy-*(jy+1))/frame_rate; x_file << ",";
            x_file<< (*jz-*(jz+1))/frame_rate; x_file << ",";*/

           /// distance in each direction 
      /*       x_file<< *jx-*(jx+1); x_file << ",";
             x_file<< *jy-*(jy+1); x_file << ",";
             x_file<< *jz-*(jz+1); x_file << ",";*/          

      //  jx++;    jy++;    jz++;
////////////////////////////// Left elbow//////////////////		
       
        /*   if(max_lx!=min_lx)  *lx=(*lx-min_lx)/(max_lx-min_lx);
           if(max_ly!=min_ly)  *ly=(*ly-min_ly)/(max_ly-min_ly);
           if(max_lz!=min_lz)  *lz=(*lz-min_lz)/(max_lz-min_lz);*/
		
         // x_file << ",";  
        /*  x_file<< *lx;                
	      x_file << ",";
	      lx++;*/

         // x_file << ","; 
         /* x_file<< *ly;                
	      x_file << ",";
	      ly++;*/
 
          //x_file << ","; 
         /* x_file<< *lz;            
	      x_file << ",";
	      lz++;*/

         /// temporal rotations
            x_file<< *lr;   
            x_file << ",";
            lr++;

            x_file<< *lp;   
            x_file << ",";
            lp++;

            x_file<< *lw;   
            x_file << ",";
            lw++;

           /// Velocity total
        //    x_file<< sqrt(pow(*lx-*(lx+1),2)+pow(*ly-*(ly+1),2)+pow(*lz-*(lz+1),2))/frame_rate;  x_file << ",";
    
           /// Velocity of each direction 
         /*   x_file<< (*lx-*(lx+1))/frame_rate;  x_file << ",";
            x_file<< (*ly-*(ly+1))/frame_rate;  x_file << ",";
            x_file<< (*lz-*(lz+1))/frame_rate;  x_file << ",";*/

         /// distance in each direction 
           /*  x_file<< *lx-*(lx+1);   x_file << ",";
             x_file<< *ly-*(ly+1);   x_file << ",";
             x_file<< *lz-*(lz+1);   x_file << ",";*/
        
        // lx++;  ly++;  lz++;
////////////////////////////////// Head /////////////////////////		
	
           /*if(max_mx!=min_mx)  *mx=(*mx-min_mx)/(max_mx-min_mx);
           if(max_my!=min_my)  *my=(*my-min_my)/(max_my-min_my);
           if(max_mz!=min_mz)  *mz=(*mz-min_mz)/(max_mz-min_mz);*/

             //x_file << ",";
            /* x_file<< *mx;
	         x_file << ",";
	         mx++;*/

             //x_file << ","; 
             /*x_file<< *my;
	         x_file << ",";
	         my++;*/

             //x_file << ","; 
            /* x_file<< *mz;
	         x_file << ",";
	         mz++;*/

            /// temporal rotations
            x_file<< *mr;   
            x_file << ",";
            mr++;

            x_file<< *mp;   
            x_file << ",";
            mp++;

            x_file<< *mw;   
            x_file << ",";
            mw++;

             /// Velocity total
         //   x_file<< sqrt(pow(*mx-*(mx+1),2)+ pow(*my-*(my+1),2)+ pow(*mz-*(mz+1),2))/frame_rate;  x_file << ",";
 
            /// Velocity of each direction 
         /*   x_file<< (*mx-*(mx+1))/frame_rate;  x_file << ",";
            x_file<< (*my-*(my+1))/frame_rate;  x_file << ",";
            x_file<< (*mz-*(mz+1))/frame_rate;  x_file << ",";*/

          /// distance in each direction 
            /*  x_file<< *mx-*(mx+1);   x_file << ",";
              x_file<< *my-*(my+1);   x_file << ",";
              x_file<< *mz-*(mz+1);   x_file << ",";*/

       //    mx++;    my++;    mz++;
////////////////////////////////// Neck /////////////////////////		
         
          /* if(max_nx!=min_nx)  *nx=(*nx-min_nx)/(max_nx-min_nx);
           if(max_ny!=min_ny)  *ny=(*ny-min_ny)/(max_ny-min_ny);
           if(max_nz!=min_nz)  *nz=(*nz-min_nz)/(max_nz-min_nz);*/
	
            // x_file << ",";
            /* x_file<< *nx;    
             x_file << ",";            
	         nx++;*/

             //x_file << ",";
            /* x_file<< *ny;   
             x_file << ",";           
	         ny++;*/

             //x_file << ","; 
            /* x_file<< *nz;
	         x_file << ",";
	         nz++;*/
       
            /// rotations
        /*    x_file<< *nr;   
            x_file << ",";
            nr++;

            x_file<< *np;   
            x_file << ",";
            np++;

            x_file<< *nw;   
            x_file << ",";
            nw++;*/

             /// Velocity total for the joint
           // x_file<< sqrt(pow(*nx-*(nx+1),2)+ pow(*ny-*(ny+1),2)+ pow(*nz-*(nz+1),2)) /frame_rate; x_file << ",";
 
            /// Velocity of each direction 
          /*  x_file<< (*nx-*(nx+1))/frame_rate; x_file << ",";
            x_file<< (*ny-*(ny+1))/frame_rate; x_file << ",";
            x_file<< (*nz-*(nz+1))/frame_rate; x_file << ",";

           /// distance in each direction 
                x_file<< *nx-*(nx+1);    x_file << ",";
                x_file<< *ny-*(ny+1);    x_file << ",";
                x_file<< *nz-*(nz+1);    x_file << ",";*/
          
       //      nx++;   ny++;   nz++;
//////////////////////////////Right Shoulder /////////////////////////////////

         /*  if(max_qx!=min_qx)  *qx=(*qx-min_qx)/(max_qx-min_qx);
           if(max_qy!=min_qy)  *qy=(*qy-min_qy)/(max_qy-min_qy);
           if(max_qz!=min_qz)  *qz=(*qz-min_qz)/(max_qz-min_qz);*/

         //x_file << ",";
        /* x_file<< *qx;	                   
	     x_file << ",";
	     qx++;*/

        // x_file << ","; 
        /* x_file<< *qy;              
	     x_file << ",";
	     qy++;*/

         //x_file << ","; 
        /* x_file<< *qz;              
	     x_file << ",";
	     qz++;*/

        /// temporal rotations
            x_file<< *qr;   
            x_file << ",";
            qr++;

            x_file<< *qp;   
            x_file << ",";
            qp++;

            x_file<< *qw;   
            x_file << ",";
            qw++;

             /// Velocity total
        //    x_file<< sqrt(pow(*qx-*(qx+1),2)+pow(*qy-*(qy+1),2)+ pow(*qz-*(qz+1),2))/frame_rate;   x_file << ",";
 
        /*    /// Velocity of each direction 
            x_file<< (*qx-*(qx+1))/frame_rate; x_file << ",";
            x_file<< (*qy-*(qy+1))/frame_rate; x_file << ",";
            x_file<< (*qz-*(qz+1))/frame_rate; x_file << ",";

            /// distance in each direction 
               x_file<< *qx-*(qx+1);    x_file << ",";
               x_file<< *qy-*(qy+1);    x_file << ",";
               x_file<< *qz-*(qz+1);    x_file << ",";
 
           qx++;   qy++;  qz++;*/
//////////////////////////////Left Shoulder /////////////////////////////////

        /*   if(max_px!=min_px)  *px=(*px-min_px)/(max_px-min_px);
           if(max_py!=min_py)  *py=(*py-min_py)/(max_py-min_py);
           if(max_pz!=min_pz)  *pz=(*pz-min_pz)/(max_pz-min_pz);*/

         //x_file << ","; 
        /* x_file<< *px;               
	     x_file << ",";
	     px++;*/

        // x_file << ","; 
         /*x_file<< *py;             
	     x_file << ",";
	     py++;*/

         //x_file << ",";
        /* x_file<< *pz;             
	     x_file << ",";
	     pz++;*/

        /// temporal rotations
            x_file<< *pr;   
            x_file << ",";
            pr++;

            x_file<< *pp;   
            x_file << ",";
            pp++;

            x_file<< *pw;   
            x_file << ",";
            pw++;

             /// Velocity total
          //  x_file<< sqrt(pow(*px-*(px+1),2)+pow(*py-*(py+1),2)+ pow(*pz-*(pz+1),2))/frame_rate;   x_file << ",";
 
            /// Velocity of each direction 
        /*    x_file<< (*px-*(px+1))/frame_rate;  x_file << ",";
            x_file<< (*py-*(py+1))/frame_rate;  x_file << ",";
            x_file<< (*pz-*(pz+1))/frame_rate;  x_file << ",";*/

          /// distance in each direction   
         /*     x_file<< *px-*(px+1);  x_file << ",";
              x_file<< *py-*(py+1);   x_file << ",";
              x_file<< *pz-*(pz+1);   x_file << ",";

           px++;  py++;  pz++;*/

////////////////////////////////// Spatial rotations ////////////////////////

////////////////////////////////// Teta1 ////////////////////////
               /*if( isnan(*teta1)==false)  {*/ x_file<< *teta1;
	                                    x_file << ",";
                                           // x_file<< (*teta1+*(teta1+1)+*(teta1+2))/3;
                                          //  x_file << ",";
	                                    teta1++;
		                        //  }
            //  else   teta1++;
////////////////////////////////// Teta2 ////////////////////////
            /*  if( isnan(*teta2)==false)  { */x_file<< *teta2;
	                                   x_file << ",";
                                         //  x_file<< (*teta2+*(teta2+1)+*(teta2+2))/3;
                                         //  x_file << ",";
	                                   teta2++;
                                   //  }
            //  else   teta2++;
////////////////////////////////// Teta3 ////////////////////////
             /*   if( isnan(*teta3)==false)  {*/x_file<< *teta3;
	                                    x_file << ",";    
                                           // x_file<< (*teta3+*(teta3+1)+*(teta3+2))/3;
	                                   // x_file << ",";
                                            teta3++;
                                         //  }
             // else   teta3++;
////////////////////////////////// Teta4 ////////////////////////
             /*  if( isnan(*teta4)==false)  {*/x_file<< *teta4;
	                                   x_file << ",";    
                                           x_file<< (*teta4+*(teta4+1)+*(teta4+2))/3;
                                           x_file << ",";
	                                   teta4++;
                                  //   }
            //  else   teta4++;
////////////////////////////////// Teta5 ////////////////////////
           /*   if( isnan(*teta5)==false)  {*/x_file<< *teta5;
             			          x_file << ",";           
                                         // x_file<< (*teta5+*(teta5+1)+*(teta5+2))/3;
                                        //  x_file << ",";
	                                  teta5++;
                                     //   }
            //  else   teta5++;
//******************************************** pixel motion ****************************

 //x_file<<*r;	 x_file << ",";  r++;


    }

    
    

    cout <<"nombre d'attributs par ligne:" << /*right_hand_x.size()*/160*taille << endl;
   
  //  cout <<"nombre d'attributs pose:" << pose_z.size() << endl;

    x_file << 0;
    x_file << "\n";
    
 /* cout << "pose VALUES TARTS NOW. KEEP IN MIND"<<endl;
    for (vector<double>::iterator i = pose_z.begin(); i != pose_z.begin()+100;++i){
		cout << *i << endl;
		x_file << *i;
		x_file << ",";
	}*/
  
   /* cout <<"Y VALUES TARTS NOW. KEEP IN MIND"<<endl;
    for (vector<double>::iterator i = right_hand_y.begin(); i != right_hand_y.end();++i){
		cout << *i << endl;
		x_file << *i;
		x_file << ",";
	}
    x_file << "\n";
    
    cout <<"Z VALUES TARTS NOW. KEEP IN MIND"<<endl;
    
    for (vector<double>::iterator i = right_hand_z.begin(); i != right_hand_z.end();++i){
		cout << *i << endl;
		x_file << *i;
		x_file << ",";
    }
    x_file << "\n";*/
     

    x_file.close();



	return 0;
};
