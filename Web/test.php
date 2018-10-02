<?php

include "EduCore.class.php";
include "ddb.class.php";
class EduCourse extends EduCore
{
    public function __construct($sid = "", $password = "", $style = 1, $session_id = ''){
        $this->sid = $sid;
        $this->password =$password;
        $this->setSession($session_id);
        $this->snoopy = $this->init();
        $this->style = $style;
    }

    public function getData($value='')
    {
        $course_url = 'http://jwxt.xtu.edu.cn/jsxsd/xskb/xskb_list.do';
        $snoopy = $this->snoopy;

        $data = $snoopy->results;

        if ($snoopy->status != 200) {
            $this->setMsg(3);
        }

#        if (preg_match('/学生个人中心/', $data)) {
		if(preg_match('/'.$this->sid.'/', $data)){
			$this->loginStatus = 1;
            $this->setMsg(0);
        } elseif (preg_match('/修改密码/', $data)) {
            $this->loginStatus = 1;
            $this->setMsg(6);
            exit("{\"code\":$this->code,\"msg\":\"$this->msg\"}");

        } else {
            $data = iconv('gbk', 'utf-8', $snoopy->results);
            if (preg_match('/用户名或密码错误/', $data)) {
                $this->setMsg(1);
                exit("{\"code\":$this->code,\"msg\":\"$this->msg\"}");

            } else if (preg_match('/验证码错误/', $data)) {
                $this->setMsg(5);
                exit("{\"code\":$this->code,\"msg\":\"$this->msg\"}");
			} else {
                $this->setMsg(4);
                exit("{\"code\":$this->code,\"msg\":\"$this->msg\"}");
            }
        }
        //这里调整学期
        $post_form = array('xnxq01id' => '2017-2018-2');

        $snoopy->submit($course_url, $post_form);

        $data = $snoopy->results;

        $repattern = '/style="display: none;" class="kbcontent" ?>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font><br\/>)?<font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?(<br\/>(.*?)<br\/>)?/';

        if (!preg_match_all($repattern, $data, $rematches)) {
            $post_form = array('xnxq01id' => '2016-2017-1');
            $snoopy->submit($course_url, $post_form);
            $data = $snoopy->results;
            preg_match_all($repattern, $data, $rematches);

        }
        if (preg_match('/评教未完成/', $data)) {
            exit("{\"code\":5,\"msg\":\"没有评教，获取课表失败\"}");
        }


        if ($rematches[43][14] != '') {
            //print_r($rematches);
            $info = array();
            $big_info = array();

            $maxx = count($rematches);
            for ($i = 0; $i < count($rematches[1]); $i++) {
                $num = 1;
                // 1.单节课 没上课节次的
                $week_string = $rematches[4][$i];
                $week = $this->getWeek($week_string);
                $info[$num][$i] = array('course' => $rematches[1][$i], 'location' => $rematches[6][$i], 'teacher' => $rematches[3][$i], 'week' => $week, 'week_string' => $rematches[4][$i], 'section_length' => '2');
                if ($rematches[maxx - 1][$i] != '') {
                    $section_length = $rematches[maxx - 1][$i][15]; //这里是15不要动了！
                    $info[$num][$i] = array('course' => $rematches[1][$i], 'location' => $rematches[6][$i], 'teacher' => $rematches[3][$i], 'week' => $week, 'week_string' => $rematches[4][$i], 'section_length' => $section_length);
                }
                $num += 1;
                while ($num <= (1 + count($rematches)) / 9) {
                    if ($rematches[($num - 1) * 9 - 2][$i] != '') {
                        if ($rematches[($num - 1) * 9 - 1][$i] != '') {
                            $info[$num][$i]['section_length'] = $rematches[($num - 1) * 9][$i];
                        } else {
                            $info[$num][$i]['section_length'] = '2';
                        }
                        $week_string = $rematches[$num * 9 - 5][$i];
                        $week = $this->getWeek($week_string);
                        if ($rematches[$maxx][$i] != '') {
                            $section_length = $rematches[$maxx][$i][15]; //这里是15不要动了！
                            $info[$num][$i] = array('course' => $rematches[($num - 1) * 9 + 1][$i], 'location' => $rematches[$num * 9 - 3][$i], 'teacher' => $rematches[$num * 9 - 6][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => $section_length);
                        } else {
                            $info[$num][$i] = array('course' => $rematches[($num - 1) * 9 + 1][$i], 'location' => $rematches[$num * 9 - 3][$i], 'teacher' => $rematches[$num * 9 - 6][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => '2');
                        }
                    }
                    $num += 1;
                }

                // 将info整合为big_info
                // print_r($info_6[$i]);

                $big_info[$i][0] = $info[1][$i];
                for ($j = 2; $j <= (1 + $maxx) / 9; $j++) {
                    if (isset($info[$j][$i])) {
                        $big_info[$i][$j - 1] = $info[$j][$i];
                    }
                }
            }

            $pattern = '/<div id=".*?".*?class="kbcontent1".*?>(.*?)<\/div>/';
            preg_match_all($pattern, $data, $matches_3);
        echo"<pre>";


            $cnt = 0;
            $count = 0;
            $days = array();
            $dayss = array();
            foreach ($matches_3[1] as $key => $value) {
                $count++;
                if($value!='&nbsp;'){
                    $course_day = $this->checkDay($count);
                    $course_time = $this->checkTime($count);
                    //加上section_start & section_end 属性
                    switch ($course_time) {
                        case 1:
                            for($t = 0; $t < 16; $t++){
                                if(isset($big_info[$cnt][$t])){
                                    $big_info[$cnt][$t]['section_start'] = "1";
                                }
                            }
                            break;
                        case 2:
                            for($t = 0; $t < 16; $t++){
                                if(isset($big_info[$cnt][$t])){
                                    $big_info[$cnt][$t]['section_start'] = "3";
                                }
                            }
                            break;
                        case 3:
                            for($t = 0; $t < 16; $t++){
                                if(isset($big_info[$cnt][$t])){
                                    $big_info[$cnt][$t]['section_start'] = "5";
                                }
                            }
                            break;
                        case 4:
                            for($t = 0; $t < 16; $t++){
                                if(isset($big_info[$cnt][$t])){
                                    $big_info[$cnt][$t]['section_start'] = "7";
                                }
                            }
                            break;
                        case 5:
                            for($t = 0; $t < 16; $t++){
                                if(isset($big_info[$cnt][$t])){
                                    $big_info[$cnt][$t]['section_start'] = "9";
                                }
                            }
                        default:
                            break;
                    }

                    for($t = 0; $t < 16; $t++){
                        if(isset($big_info[$cnt][$t])){
                            if( !is_numeric($big_info[$cnt][$t]['section_length']) ){
                                $big_info[$cnt][$t]['section_length'] = '2';
                            }

                            $big_info[$cnt][$t]['section_end'] = strval($big_info[$cnt][$t]['section_start'] + $big_info[$cnt][$t]['section_length'] - 1);
                        }
                    }
                    if ($this->style==3) {
                        for($t = 0; $t < 4; $t++){
                            if(isset($big_info[$cnt][$t])){
                                $big_info[$cnt][$t]['day'] = $course_day;
                            }
                        }
                    }
                    $dayss[$course_day][$course_time] = $big_info[$cnt];
                    //切换样式
                    if($this->style==1){
                        $days[$course_day][$course_time] = $big_info[$cnt];
                    } elseif ($this->style==2) {
                        $days[$course_day][] = $big_info[$cnt];
                    } elseif ($this->style==3) {
                        $days[] = $big_info[$cnt];
                    }
                    $cnt++;
                }
            }
            //print_r($big_info);
            ksort($days);
            ksort($dayss);
            // print_r($days);


            $final_data = array('code'=>0,'msg'=>'成功','data'=> $days);
            $final_data = json_encode($final_data, JSON_UNESCAPED_UNICODE);

            $dayss = json_encode($dayss,JSON_UNESCAPED_UNICODE);
            //    $dbClass = new dbClass(dbHost, dbUser, dbPassword, dbTable, dbport);
            // $sql = "SELECT * FROM course WHERE term = '". TERM_TIME . "' AND json = '$dayss' ";
            // $rs  = $dbClass->query($sql);
            // if(mysqli_num_rows($rs) <= 0){
            //     $s = substr($this->sid,0,8);
            //     $sql = "INSERT INTO course (json,sid,term) VALUES ('$dayss','$s','". TERM_TIME ."')";
            //     $dbClass->query($sql);
            // }

            print_r($final_data);
        }
        else {
            $pattern = '/style="display: none;" class="kbcontent" ?>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font><br\/>)?<font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?((<br\/>上课节次：(.*?)节)?<br\/>---------------------<br>(.*?)<br\/>(<font title=\'老师\'>(.*?)<\/font>)<br\/><font title=\'周次\(节次\)\'>(.*?)<\/font>(<br\/><font title=\'教室\'>(.*?)<\/font>)?)?(<br\/>(.*?)<br\/>)?/';


//			preg_match_all($pattern, $data, $matches);

            if (!preg_match_all($pattern, $data, $matches)) {
                $post_form = array('xnxq01id' => '2016-2017-1');
                $snoopy->submit($course_url, $post_form);
                $data = $snoopy->results;
                preg_match_all($pattern, $data, $matches);

            }
            // print_r($data);
            // print_r($matches);

            /*
                1.单节课
                2.双节课
                3.三节课
                4.四节课
                5.五节课
            */
            $info = array();
            $info_2 = array();
            $info_3 = array();
            $info_4 = array();
            $info_5 = array();
            $big_info = array();
            for ($i = 0; $i < count($matches[1]); $i++) {
                // 1.单节课 没上课节次的
                $week_string = $matches[4][$i];
                $week = $this->getWeek($week_string);
                $info[$i] = array('course' => $matches[1][$i], 'location' => $matches[6][$i], 'teacher' => $matches[3][$i], 'week' => $week, 'week_string' => $matches[4][$i], 'section_length' => '2');
                if ($matches[44][$i] != '') {
                    $section_length = $matches[44][$i][15]; //这里是15不要动了！
                    $info[$i] = array('course' => $matches[1][$i], 'location' => $matches[6][$i], 'teacher' => $matches[3][$i], 'week' => $week, 'week_string' => $matches[4][$i], 'section_length' => $section_length);
                }
                // 2.双节课的情况
                if ($matches[7][$i] != '') {
                    // $matches[7][$i]存在说明匹配到了两节课的情况
                    if ($matches[8][$i] != '') {
                        $info[$i]['section_length'] = $matches[9][$i];
                    } else {
                        $info[$i]['section_length'] = '2';
                    }
                    $week_string = $matches[13][$i];
                    $week = $this->getWeek($week_string);
                    if ($matches[44][$i] != '') {
                        $section_length = $matches[44][$i][15]; //这里是15不要动了！
                        $info_2[$i] = array('course' => $matches[10][$i], 'location' => $matches[15][$i], 'teacher' => $matches[12][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => $section_length);
                    } else {
                        $info_2[$i] = array('course' => $matches[10][$i], 'location' => $matches[15][$i], 'teacher' => $matches[12][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => '2');
                    }
                }

                // 3.三节课的情况
                //$matches[16][$i] != '' 匹配到了三节课的情况
                //$matches[17][$i] != '' 匹配到了第二个课的 '上课节数'
                if ($matches[16][$i] != '') {
                    if ($matches[17][$i] != '') {
                        $info_2[$i]['section_length'] = $matches[18][$i];
                    } else
                        $info_2[$i]['section_length'] = '2';
                    $week_string = $matches[22][$i];
                    $week = $this->getWeek($week_string);
                    if ($matches[44][$i] != '') {
                        $section_length = $matches[44][$i][15]; //这里是15不要动了！
                        $info_3[$i] = array('course' => $matches[19][$i], 'location' => $matches[24][$i], 'teacher' => $matches[21][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => $section_length);
                    } else {
                        $info_3[$i] = array('course' => $matches[19][$i], 'location' => $matches[24][$i], 'teacher' => $matches[21][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => '2');
                    }
                }

                // 4.四节课的情况
                //$matches[25][$i] != '' 匹配到了四节课的情况
                //$matches[26][$i] != '' 匹配到了第三个课的 '上课节数'
                if ($matches[25][$i] != '') {
                    if ($matches[26][$i] != '') {
                        $info_3[$i]['section_length'] = $matches[27][$i];
                    } else
                        $info_3[$i]['section_length'] = '2';
                    $week_string = $matches[31][$i];
                    $week = $this->getWeek($week_string);
                    if ($matches[44][$i] != '') {
                        $section_length = $matches[44][$i][15]; //这里是15不要动了！
                        $info_4[$i] = array('course' => $matches[28][$i], 'location' => $matches[33][$i], 'teacher' => $matches[30][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => $section_length);
                    } else {
                        $info_4[$i] = array('course' => $matches[28][$i], 'location' => $matches[33][$i], 'teacher' => $matches[30][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => '2');
                    }

                }

                //5.五节课情况
                //$matches[34][$i] != '' 说明匹配到了五三节课的情况
                //$matches[35][$i] != '' 说明匹配到了第四个课的 '上课节数'
                if ($matches[34][$i] != '') {
                    if ($matches[35][$i] != '') {
                        $info_4[$i]['section_length'] = $matches[36][$i];
                    } else
                        $info_4[$i]['section_length'] = '2';

                    $week_string = $matches[40][$i];
                    $week = $this->getWeek($week_string);
                    if ($matches[44][$i] != '') {
                        $section_length = $matches[44][$i][15]; //这里是15不要动了！
                        $info_5[$i] = array('course' => $matches[37][$i], 'location' => $matches[42][$i], 'teacher' => $matches[39][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => $section_length);
                    } else {
                        $info_5[$i] = array('course' => $matches[37][$i], 'location' => $matches[42][$i], 'teacher' => $matches[39][$i], 'week' => $week, 'week_string' => $week_string, 'section_length' => '2');
                    }

                }


                // 将info整合为big_info
//                print_r($info_3[$i]);
                $big_info[$i][0] = $info[$i];
                if (isset($info_2[$i])) {
                    $big_info[$i][1] = $info_2[$i];
                }
                if (isset($info_3[$i])) {
                    $big_info[$i][2] = $info_3[$i];
                }
                if (isset($info_4[$i])) {
                    $big_info[$i][3] = $info_4[$i];
                }
                if (isset($info_5[$i])) {
                    $big_info[$i][4] = $info_5[$i];
                }

            }
        //给所有匹配结果编上序号
        $pattern = '/<div id=".*?".*?class="kbcontent1".*?>(.*?)<\/div>/';
        preg_match_all($pattern, $data, $matches_3);


        // print_r($big_info);
        $cnt = 0;
        $count = 0;
        $days = array();
        $dayss = array();
        foreach ($matches_3[1] as $key => $value) {
            $count++;
            if ($value != '&nbsp;') {
                $course_day = $this->checkDay($count);
                $course_time = $this->checkTime($count);
                //加上section_start & section_end 属性
                switch ($course_time) {
                    case 1:
                        for ($t = 0; $t < 4; $t++) {
                            if (isset($big_info[$cnt][$t])) {
                                $big_info[$cnt][$t]['section_start'] = "1";
                            }
                        }
                        break;
                    case 2:
                        for ($t = 0; $t < 4; $t++) {
                            if (isset($big_info[$cnt][$t])) {
                                $big_info[$cnt][$t]['section_start'] = "3";
                            }
                        }
                        break;
                    case 3:
                        for ($t = 0; $t < 4; $t++) {
                            if (isset($big_info[$cnt][$t])) {
                                $big_info[$cnt][$t]['section_start'] = "5";
                            }
                        }
                        break;
                    case 4:
                        for ($t = 0; $t < 4; $t++) {
                            if (isset($big_info[$cnt][$t])) {
                                $big_info[$cnt][$t]['section_start'] = "7";
                            }
                        }
                        break;
                    case 5:
                        for ($t = 0; $t < 4; $t++) {
                            if (isset($big_info[$cnt][$t])) {
                                $big_info[$cnt][$t]['section_start'] = "9";
                            }
                        }
                    default:
                        break;
                }

                for ($t = 0; $t < 4; $t++) {
                    if (isset($big_info[$cnt][$t])) {
                        if (!is_numeric($big_info[$cnt][$t]['section_length'])) {
                            $big_info[$cnt][$t]['section_length'] = '2';
                        }

                        $big_info[$cnt][$t]['section_end'] = strval($big_info[$cnt][$t]['section_start'] + $big_info[$cnt][$t]['section_length'] - 1);
                    }
                }
                if ($this->style == 3) {
                    for ($t = 0; $t < 4; $t++) {
                        if (isset($big_info[$cnt][$t])) {
                            $big_info[$cnt][$t]['day'] = $course_day;
                        }
                    }
                }
                $dayss[$course_day][$course_time] = $big_info[$cnt];
                //切换样式
                if ($this->style == 1) {
                    $days[$course_day][$course_time] = $big_info[$cnt];
                } elseif ($this->style == 2) {
                    $days[$course_day][] = $big_info[$cnt];
                } elseif ($this->style == 3) {
                    $days[] = $big_info[$cnt];
                }
                $cnt++;
            }
        }

        ksort($days);
        ksort($dayss);
        // print_r($days);


        $final_data = array('code' => 0, 'msg' => '成功', 'data' => $days);
        $final_data = json_encode($final_data, JSON_UNESCAPED_UNICODE);

        $dayss = json_encode($dayss, JSON_UNESCAPED_UNICODE);
        //    $dbClass = new dbClass(dbHost, dbUser, dbPassword, dbTable, dbport);
        // $sql = "SELECT * FROM course WHERE term = '". TERM_TIME . "' AND json = '$dayss' ";
        // $rs  = $dbClass->query($sql);
        // if(mysqli_num_rows($rs) <= 0){
        //     $s = substr($this->sid,0,8);
        //     $sql = "INSERT INTO course (json,sid,term) VALUES ('$dayss','$s','". TERM_TIME ."')";
        //     $dbClass->query($sql);
        // }

        print_r($final_data);
    }

    }

    /*
     *  确定第几节课
    */
    function checkTime($count){
        if($count<=7){
            return 1;
        } elseif($count>7 && $count<=14) {
            return 2;
        } elseif($count>14 && $count<=21) {
            return 3;
        } elseif($count>21 && $count<=28) {
            return 4;
        } elseif($count>28 && $count<=35) {
            return 5;
        }

    }
    /*
        确定星期几
    */
    function checkDay($count){

        if($count%7==1){
            return 1;
        } elseif ($count%7==2) {
            return 2;
        } elseif ($count%7==3) {
            return 3;
        } elseif ($count%7==4) {
            return 4;
        } elseif ($count%7==5) {
            return 5;
        } elseif ($count%7==6) {
            return 6;
        } elseif ($count%7==0) {
            return 7;
        }
    }

    protected function getAddNum($string){
        if(preg_match('/单周/', $string)) {
            return 1;
        } elseif (preg_match('/双周/', $string)){
            return 2;
        } elseif (preg_match('/周/', $string)){
            return 3;
        } else {
            return 3;
        }
    }

    protected function replaceArray($oldString, $addNum){
        if($addNum==1){
            $newString = str_replace('(单周)','',$oldString);
            return $newString;
        } elseif ($addNum==2) {
            $newString = str_replace('(双周)','',$oldString);
            return $newString;
        } elseif ($addNum==3) {
            $newString = str_replace('(周)','',$oldString);
            return $newString;
        } else {
            return $oldString;
        }
    }
    protected function getWeek($string){
        $arr = explode(',',$string);
        $str = '';
        foreach ($arr as $item) {
            if(preg_match('/-/', $item)){

                $addNum = $this->getAddNum($string);
                $item = $this->replaceArray($item, $addNum);
                $weekArr = explode('-', $item);
                $startWeek = $weekArr[0];
                $endWeek   = $weekArr[1];
                if ( ($startWeek%2==1 && $addNum==2) || ($startWeek%2==0 && $addNum==1) ){
                    $num = $startWeek + 1;
                } else {
                    $num = $startWeek;
                }
                while($num <= $endWeek){
                    if($addNum == 3){
                        $str[] = $num;
                        $num = $num + 1;
                    } else {
                        $str[] = $num;
                        $num = $num + 2;
                    }
                }
            } else {
                $addNum = $this->getAddNum($item);
                $item = $this->replaceArray($item, $addNum);
                $str[] = $item;
            }
        }
        $week_string = '';
        foreach ($str as $key => $value) {
            if($key+1 != count($str)){
                $week_string = $week_string.$value.',';
            } else {
                $week_string = $week_string.$value;
            }
        }
        return $week_string;
    }
    //这个函数走了弯路，上面有个更好的，但是写了这么久，留在这里吧= =
    function getWeek_1($string){
        //一. 2-17(周) 类型
        $pattern_1 = '/(\d+)\-(\d+)\(周\)/';
        //二. 1-11,14(周) 类型
        $pattern_2 ='/(\d+)\-(\d+)\,(\d+)\(周\)/';
        //三. 3-17(单周) 类型
        $pattern_3 ='/(\d+)\-(\d+)\(单周\)/';
        //四. 2-16(双周) 类型
        $pattern_4 ='/(\d+)\-(\d+)\(双周\)/';
        //五. 1-9,12-16(周) 类型
        $pattern_5 ='/(\d+)\-(\d+)\,(\d+)\-(\d+)\(周\)/';
        //六. 15(单周)
        $pattern_6 ='/(\d+)\(单周\)/';
        if (preg_match_all($pattern_5, $string, $matches)) { //五. 1-9,12-16(周) 类型

            $ran = range($matches[1][0], $matches[2][0]);
            $ran_2 = range($matches[3][0], $matches[4][0]);

            $str = "";
            foreach ($ran as $key => $value)
                $str = $str.$value.',';

            $count = count($ran_2);
            foreach ($ran_2 as $key => $value) {
                if ($key+1 != $count)
                    $str = $str.$value.',';
                elseif ($key+1 == $count) {
                    $str = $str.$value;
                }
            }

            return $str;

        }
        if(preg_match($pattern_1, $string, $matches)){ //一. 2-17(周) 类型

            $ran = range($matches[1], $matches[2]);
            $str = "";
            $count = count($ran);
            foreach ($ran as $key => $value) {
                if ($key+1 != $count)
                    $str = $str.$value.',';
                elseif ($key+1 == $count) {
                    $str = $str.$value;
                }
            }

            return $str;

        }
        if (preg_match_all($pattern_2, $string, $matches)) { //二. 1-11,14(周) 类型

            $ran = range($matches[1][0], $matches[2][0]);
            $single_num = $matches[3][0];

            $str = "";
            foreach ($ran as $key => $value)
                $str = $str.$value.',';

            $str = $str.$single_num;
            return $str;

        }

        if(preg_match_all($pattern_3, $string, $matches)){ //三. 3-17(单周) 类型
            $ran = range($matches[1][0], $matches[2][0]);
            $str = "";
            $count = count($ran);
            foreach ($ran as $key => $value) {
                if($value%2==1){
                    if ($key+1 != $count)
                        $str = $str.$value.',';
                    elseif ($key+1 == $count) {
                        $str = $str.$value;
                    }
                }
            }
            return $str;
        }

        if(preg_match_all($pattern_4, $string, $matches)){ //四. 2-16(双周) 类型

            $ran = range($matches[1][0], $matches[2][0]);
            $str = "";
            $count = count($ran);
            foreach ($ran as $key => $value) {
                if($value%2==0){
                    if ($key+1 != $count)
                        $str = $str.$value.',';
                    elseif ($key+1 == $count) {
                        $str = $str.$value;
                    }
                }
            }
            return $str;
        }

        if (preg_match_all($pattern_5, $string, $matches)) { //五. 1-9,12-16(周) 类型

            $ran = range($matches[1][0], $matches[2][0]);
            $str = "";
            foreach ($ran as $key => $value)
                $str = $str.$value.',';


            return $str;

        }

        if (preg_match_all($pattern_6, $string, $matches)) { //六. 15(单周) 类型

            $ran = $matches[1][0];


            $str = "";
            $str .= $ran;


            return $str;

        }
    }
}



?>
