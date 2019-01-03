### 筛选数据
1.  从视频中抽取图片
```
mkdir images
ffmpeg -i <videoName> images/%05d.png
```
2.  从bag中提取LiDAR
```
roscore
```
按 'Ctrl + Shift + t'，在terminal中打开New Tab
```
rosbag play <bagName>
```
等待bag回放开始，按 'Ctrl + Shift + t'，在terminal中再次打开New Tab
```
rostopic list
```
从列表中找到LiDAR对应的topic
```
rosrun pcl_ros bag_to_pcd <bagName> <topicName> <outputDirectory>
```
3. 筛选数据
运行select.sh筛选数据
```
bash select.sh
```
生成
```
select.txt select_lidar.txt images_select/ LiDARs_select/ images_rename/ LiDARs_rename/
```
4. Camera-LiDAR Calibration
使用MATLAB工具标定相机内参CameraParams，导出到workspace
运行MATLAB标定程序，修改文件夹路径framePath
