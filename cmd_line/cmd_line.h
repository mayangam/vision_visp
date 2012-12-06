#ifndef __CMD_LINE_H__
#define __CMD_LINE_H__
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <exception>
#include <string>
#include <visp/vpConfig.h>
#include <visp/vpPoint.h>
namespace po = boost::program_options;
class CmdLine{
 private:
  boost::program_options::variables_map vm_;
  bool verbose_;
  bool show_fps_;
  bool show_plot_;
  bool log_pose_;
  bool should_exit_;
  std::string video_channel_;
  double inner_ratio_;
  double outer_ratio_;
  double var_limit_;
  bool adhoc_recovery_;
  bool adhoc_recovery_display_;
  double adhoc_recovery_ratio_;
  unsigned int adhoc_recovery_treshold_;
  double adhoc_recovery_size_;
  std::vector<double> hinkley_range_;
  int dmx_timeout_;
  int mbt_convergence_steps_;
  double mbt_dynamic_range_;
  std::string data_dir_;
  std::string pattern_name_;
  std::string var_file_;
  std::string single_image_name_;
  std::vector<vpPoint> flashcode_points_3D_;
  std::vector<vpPoint> inner_points_3D_,outer_points_3D_;

  po::options_description prog_args;
  std::vector<double> flashcode_coordinates,inner_coordinates,outer_coordinates;
  std::string log_file_pattern_,input_file_pattern_;
  std::string config_file;
  void loadConfig(std::string& config_file);
  void common();
 public:
  enum DETECTOR_TYPE{
    DMTX, ZBAR
  };
  enum TRACKER_TYPE{
    KLT, MBT, KLT_MBT
  };

  CmdLine(int argc,char**argv);
  CmdLine(std::string& config_file);

  bool show_plot();

  bool using_hinkley();

  vpCameraParameters get_cam_calib_params();

  double get_hinkley_alpha();

  double get_hinkley_delta();

  bool dmtx_only();

  bool should_exit();

  std::string get_log_file_pattern();

  std::string get_input_file_pattern();

  std::string get_video_channel();

  bool show_fps();

  int get_mbt_convergence_steps();

  double get_mbt_dynamic_range();

  double get_adhoc_recovery_size();

  bool log_checkpoints();

  bool log_pose();

  bool using_mbt_dynamic_range();

  bool get_verbose();

  int get_dmx_timeout();

  double get_inner_ratio();

  double get_outer_ratio();

  bool using_data_dir();

  bool using_video_camera();

  std::string get_data_dir();

  std::string get_pattern_name();

  std::string get_wrl_file();

  std::string get_xml_file();

  std::string get_init_file();

  std::string get_var_file();

  bool using_single_image();

  bool using_var_file();

  double get_var_limit();

  double get_adhoc_recovery_ratio();

  unsigned int get_adhoc_recovery_treshold();
  bool get_adhoc_recovery_display();

  bool using_adhoc_recovery();

  bool using_var_limit();

  bool logging_video();

  std::string get_single_image_path();

  std::vector<vpPoint>& get_flashcode_points_3D();
  std::vector<vpPoint>& get_inner_points_3D();
  std::vector<vpPoint>& get_outer_points_3D();

  DETECTOR_TYPE get_detector_type();

  TRACKER_TYPE get_tracker_type();

  void set_data_directory(std::string dir);
};
#endif
