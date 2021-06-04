/*
 Navicat Premium Data Transfer

 Source Server         : mysqlForProject
 Source Server Type    : MySQL
 Source Server Version : 50562
 Source Host           : localhost:3306
 Source Schema         : sc_pro

 Target Server Type    : MySQL
 Target Server Version : 50562
 File Encoding         : 65001

 Date: 03/06/2021 20:21:38
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for admin
-- ----------------------------
DROP TABLE IF EXISTS `admin`;
CREATE TABLE `admin`  (
  `id` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `username` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `password` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of admin
-- ----------------------------
INSERT INTO `admin` VALUES ('hk560', 'HK560', '01');
INSERT INTO `admin` VALUES ('tc0001', 'teacher0001', 'pw0001');
INSERT INTO `admin` VALUES ('tc0002', 'teacher0002', 'pw0002');
INSERT INTO `admin` VALUES ('tc0003', 'teacher0003', 'pw0003');

-- ----------------------------
-- Table structure for c
-- ----------------------------
DROP TABLE IF EXISTS `c`;
CREATE TABLE `c`  (
  `Cno` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `name` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `teacher` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `credit` float NULL DEFAULT NULL,
  PRIMARY KEY (`Cno`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of c
-- ----------------------------
INSERT INTO `c` VALUES ('C0001', '数据库原理', '郑吉平', 3);
INSERT INTO `c` VALUES ('C0002', '操作系统', '刘亮', 3.5);
INSERT INTO `c` VALUES ('C0003', '模式识别', '梁栋', 2);
INSERT INTO `c` VALUES ('C0004', '数字图像处理', '朱旗', 2);

-- ----------------------------
-- Table structure for s
-- ----------------------------
DROP TABLE IF EXISTS `s`;
CREATE TABLE `s`  (
  `Sno` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `name` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `sex` char(2) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `age` smallint(6) NULL DEFAULT NULL,
  `major` char(30) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  `password` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NULL DEFAULT NULL,
  PRIMARY KEY (`Sno`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of s
-- ----------------------------
INSERT INTO `s` VALUES ('01', 'name', '女', 11, '计科', '01');
INSERT INTO `s` VALUES ('hk560', '翎', '男', 19, '计科', '01');
INSERT INTO `s` VALUES ('st0001', 'name', '女', 11, '计科', '01');
INSERT INTO `s` VALUES ('st0002', 'student0002', '女', 18, '物联网工程', 'pw0002');

-- ----------------------------
-- Table structure for sc
-- ----------------------------
DROP TABLE IF EXISTS `sc`;
CREATE TABLE `sc`  (
  `Sno` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `Cno` char(10) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `grade` smallint(6) NULL DEFAULT NULL,
  PRIMARY KEY (`Sno`, `Cno`) USING BTREE,
  INDEX `Cno`(`Cno`) USING BTREE,
  CONSTRAINT `SC_ibfk_1` FOREIGN KEY (`Sno`) REFERENCES `s` (`Sno`) ON DELETE RESTRICT ON UPDATE RESTRICT,
  CONSTRAINT `SC_ibfk_2` FOREIGN KEY (`Cno`) REFERENCES `c` (`Cno`) ON DELETE RESTRICT ON UPDATE RESTRICT
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of sc
-- ----------------------------
INSERT INTO `sc` VALUES ('hk560', 'C0001', NULL);
INSERT INTO `sc` VALUES ('st0001', 'C0001', 98);
INSERT INTO `sc` VALUES ('st0001', 'C0002', 87);
INSERT INTO `sc` VALUES ('st0002', 'C0001', 100);
INSERT INTO `sc` VALUES ('st0002', 'C0002', 79);
INSERT INTO `sc` VALUES ('st0002', 'C0003', 88);

-- ----------------------------
-- Table structure for t
-- ----------------------------
DROP TABLE IF EXISTS `t`;
CREATE TABLE `t`  (
  `tno` int(10) NOT NULL,
  `tname` char(20) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `twork` char(2) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  `twage` int(8) NOT NULL,
  `tcourse` char(30) CHARACTER SET utf8 COLLATE utf8_general_ci NOT NULL,
  PRIMARY KEY (`tno`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8 COLLATE = utf8_general_ci ROW_FORMAT = Compact;

-- ----------------------------
-- Records of t
-- ----------------------------
INSERT INTO `t` VALUES (1001, '李老师', '教师', 8000, '数据结构');
INSERT INTO `t` VALUES (1002, '黄老师', '教师', 9000, '操作系统');
INSERT INTO `t` VALUES (1003, '金老师', '主任', 10000, '计算机网络');

SET FOREIGN_KEY_CHECKS = 1;
