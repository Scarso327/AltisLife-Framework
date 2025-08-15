CREATE DATABASE  IF NOT EXISTS `altislife` /*!40100 DEFAULT CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci */ /*!80016 DEFAULT ENCRYPTION='N' */;
USE `altislife`;
-- MySQL dump 10.13  Distrib 8.0.40, for Win64 (x86_64)
--
-- Host: localhost    Database: altislife
-- ------------------------------------------------------
-- Server version	8.0.40

/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!50503 SET NAMES utf8 */;
/*!40103 SET @OLD_TIME_ZONE=@@TIME_ZONE */;
/*!40103 SET TIME_ZONE='+00:00' */;
/*!40014 SET @OLD_UNIQUE_CHECKS=@@UNIQUE_CHECKS, UNIQUE_CHECKS=0 */;
/*!40014 SET @OLD_FOREIGN_KEY_CHECKS=@@FOREIGN_KEY_CHECKS, FOREIGN_KEY_CHECKS=0 */;
/*!40101 SET @OLD_SQL_MODE=@@SQL_MODE, SQL_MODE='NO_AUTO_VALUE_ON_ZERO' */;
/*!40111 SET @OLD_SQL_NOTES=@@SQL_NOTES, SQL_NOTES=0 */;

--
-- Table structure for table `base_bids`
--

DROP TABLE IF EXISTS `base_bids`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `base_bids` (
  `id` int NOT NULL AUTO_INCREMENT,
  `base` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `group_id` int NOT NULL,
  `bid` int NOT NULL DEFAULT '0',
  `active` tinyint NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  KEY `FK_base_bids_groups` (`group_id`),
  CONSTRAINT `FK_base_bids_groups` FOREIGN KEY (`group_id`) REFERENCES `groups` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `candidates`
--

DROP TABLE IF EXISTS `candidates`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `candidates` (
  `id` int NOT NULL AUTO_INCREMENT,
  `name` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `pid` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `active` tinyint NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  KEY `FK_candidates_players` (`pid`),
  CONSTRAINT `FK_candidates_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `community_goal_contributions`
--

DROP TABLE IF EXISTS `community_goal_contributions`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `community_goal_contributions` (
  `id` int NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) COLLATE utf8mb4_general_ci NOT NULL,
  `goalId` int NOT NULL DEFAULT '0',
  `contribution` int NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `pid` (`pid`,`goalId`),
  KEY `FK_community_goal_contributions_community_goals` (`goalId`),
  CONSTRAINT `FK_community_goal_contributions_community_goals` FOREIGN KEY (`goalId`) REFERENCES `community_goals` (`id`) ON DELETE CASCADE,
  CONSTRAINT `FK_community_goal_contributions_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=9 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `community_goals`
--

DROP TABLE IF EXISTS `community_goals`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `community_goals` (
  `id` int NOT NULL AUTO_INCREMENT,
  `goal_cfg` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `end_date` date NOT NULL,
  `paid` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB AUTO_INCREMENT=74 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `group_alliances`
--

DROP TABLE IF EXISTS `group_alliances`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `group_alliances` (
  `id` int NOT NULL AUTO_INCREMENT,
  `group_a_id` int NOT NULL,
  `group_b_id` int NOT NULL,
  `active` tinyint NOT NULL DEFAULT '1',
  UNIQUE KEY `IDX_UNIQUE_PAIR` (`group_a_id`,`group_b_id`),
  KEY `id` (`id`),
  KEY `FK_GROUP_B` (`group_b_id`),
  CONSTRAINT `FK_GROUP_A` FOREIGN KEY (`group_a_id`) REFERENCES `groups` (`id`) ON DELETE CASCADE ON UPDATE RESTRICT,
  CONSTRAINT `FK_GROUP_B` FOREIGN KEY (`group_b_id`) REFERENCES `groups` (`id`) ON DELETE CASCADE ON UPDATE RESTRICT
) ENGINE=InnoDB AUTO_INCREMENT=5 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `groups`
--

DROP TABLE IF EXISTS `groups`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `groups` (
  `id` int NOT NULL AUTO_INCREMENT,
  `owner` varchar(17) COLLATE utf8mb4_general_ci NOT NULL,
  `type` varchar(32) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `tag` varchar(5) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `name` varchar(32) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `level` int DEFAULT '1',
  `xp` int DEFAULT '0',
  `bank` int DEFAULT '0',
  `tax` float DEFAULT '0',
  `active` tinyint NOT NULL DEFAULT '1',
  `premium` tinyint NOT NULL DEFAULT '0',
  `ranks` text COLLATE utf8mb4_general_ci NOT NULL,
  `buffs` text COLLATE utf8mb4_general_ci NOT NULL,
  `deposit` tinyint NOT NULL DEFAULT '6',
  `withdraw` tinyint NOT NULL DEFAULT '6',
  `rank` tinyint NOT NULL DEFAULT '6',
  `invite` tinyint NOT NULL DEFAULT '6',
  `kick` tinyint NOT NULL DEFAULT '6',
  `premium_expire` date NOT NULL DEFAULT (now()),
  `insert_time` timestamp NOT NULL DEFAULT (now()),
  PRIMARY KEY (`id`),
  UNIQUE KEY `unique_name` (`name`),
  UNIQUE KEY `unique_tag` (`tag`) USING BTREE,
  KEY `fkIdx_players_gangs` (`owner`),
  CONSTRAINT `FK_players_gangs` FOREIGN KEY (`owner`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `houses`
--

DROP TABLE IF EXISTS `houses`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `houses` (
  `id` int NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) COLLATE utf8mb4_general_ci NOT NULL,
  `classname` varchar(64) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `pos` varchar(32) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `name` varchar(32) COLLATE utf8mb4_general_ci DEFAULT '',
  `storage` text COLLATE utf8mb4_general_ci,
  `virtualStorage` text COLLATE utf8mb4_general_ci,
  `upgrades` text COLLATE utf8mb4_general_ci NOT NULL,
  `upkeepDaysLeft` int DEFAULT '30',
  `shared` tinyint DEFAULT '0',
  `sold` tinyint DEFAULT '0',
  `insert_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  UNIQUE KEY `pos` (`pos`),
  KEY `fkIdx_players_houses` (`pid`),
  CONSTRAINT `FK_players_houses` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=2 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `logs`
--

DROP TABLE IF EXISTS `logs`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `logs` (
  `id` int NOT NULL AUTO_INCREMENT,
  `event` varchar(50) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '',
  `pid` varchar(17) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '',
  `content` text CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci,
  `jsonContent` json DEFAULT NULL,
  `season` int NOT NULL DEFAULT '0',
  `insert` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `pid` (`pid`),
  CONSTRAINT `FK_logs_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=1259 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
/*!50003 CREATE*/ /*!50017 DEFINER=`root`@`localhost`*/ /*!50003 TRIGGER `logs_after_insert` AFTER INSERT ON `logs` FOR EACH ROW BEGIN
	INSERT INTO logs_queue (log_id) VALUES (NEW.id);
END */;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;

--
-- Table structure for table `logs_queue`
--

DROP TABLE IF EXISTS `logs_queue`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `logs_queue` (
  `log_id` int NOT NULL,
  `handled` tinyint NOT NULL DEFAULT '0',
  `time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  KEY `FK_logs_queue_logs` (`log_id`),
  CONSTRAINT `FK_logs_queue_logs` FOREIGN KEY (`log_id`) REFERENCES `logs` (`id`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `mail`
--

DROP TABLE IF EXISTS `mail`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `mail` (
  `id` int NOT NULL AUTO_INCREMENT,
  `pid` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `type` varchar(50) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '',
  `class` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `data` text COLLATE utf8mb4_general_ci NOT NULL,
  `daysUntilExpiry` int DEFAULT NULL,
  `timestamp` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  `claimed` tinyint NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  KEY `pid` (`pid`),
  CONSTRAINT `FK__players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=17 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `players`
--

DROP TABLE IF EXISTS `players`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `players` (
  `uid` int NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) COLLATE utf8mb4_general_ci NOT NULL,
  `name` varchar(32) COLLATE utf8mb4_general_ci NOT NULL,
  `aliases` text COLLATE utf8mb4_general_ci NOT NULL,
  `cash` int NOT NULL DEFAULT '0',
  `bankacc` int NOT NULL DEFAULT '0',
  `group_id` int NOT NULL DEFAULT '-1',
  `group_level` int NOT NULL DEFAULT '0',
  `coplevel` enum('0','1','2','3','4','5','6','7','8','9','10','11') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `collevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `npaslevel` enum('0','1','2','3','4') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `scolevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `ncalevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `mpulevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `rpulevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `sfolevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `uclevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `seglevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `cop_licenses` text COLLATE utf8mb4_general_ci NOT NULL,
  `cop_perks` text COLLATE utf8mb4_general_ci NOT NULL,
  `cop_gear` text COLLATE utf8mb4_general_ci NOT NULL,
  `cop_stats` varchar(25) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '"[100,100,0]"',
  `cop_daily_tasks` text COLLATE utf8mb4_general_ci NOT NULL,
  `cop_weekly_tasks` text COLLATE utf8mb4_general_ci NOT NULL,
  `cop_blacklisted` tinyint NOT NULL DEFAULT '0',
  `cop_wounded` tinyint NOT NULL DEFAULT '0',
  `cop_playtime` int NOT NULL DEFAULT (0),
  `mediclevel` enum('0','1','2','3','4','5','6','7','8') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `aalevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `hartlevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `hrlevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `med_licenses` text COLLATE utf8mb4_general_ci NOT NULL,
  `med_perks` text COLLATE utf8mb4_general_ci NOT NULL,
  `med_gear` text COLLATE utf8mb4_general_ci NOT NULL,
  `med_stats` varchar(25) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '"[100,100,0]"',
  `med_daily_tasks` text COLLATE utf8mb4_general_ci NOT NULL,
  `med_weekly_tasks` text COLLATE utf8mb4_general_ci NOT NULL,
  `med_blacklisted` tinyint NOT NULL DEFAULT '0',
  `med_wounded` tinyint NOT NULL DEFAULT '0',
  `med_playtime` int NOT NULL DEFAULT (0),
  `hatolevel` enum('0','1','2','3','4') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `hato_licenses` text COLLATE utf8mb4_general_ci NOT NULL,
  `hato_perks` text COLLATE utf8mb4_general_ci NOT NULL,
  `hato_gear` text COLLATE utf8mb4_general_ci NOT NULL,
  `hato_stats` varchar(25) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '"[100,100,0]"',
  `hato_daily_tasks` text COLLATE utf8mb4_general_ci NOT NULL,
  `hato_weekly_tasks` text COLLATE utf8mb4_general_ci NOT NULL,
  `hato_blacklisted` tinyint NOT NULL DEFAULT '0',
  `hato_wounded` tinyint NOT NULL DEFAULT '0',
  `hato_playtime` int NOT NULL DEFAULT (0),
  `civ_licenses` text COLLATE utf8mb4_general_ci NOT NULL,
  `civ_perks` text COLLATE utf8mb4_general_ci NOT NULL,
  `civ_gear` text COLLATE utf8mb4_general_ci NOT NULL,
  `civ_stats` varchar(25) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '"[100,100,0]"',
  `civ_daily_tasks` text COLLATE utf8mb4_general_ci NOT NULL,
  `civ_weekly_tasks` text COLLATE utf8mb4_general_ci NOT NULL,
  `civ_arrested` tinyint NOT NULL DEFAULT '0',
  `civ_prison_timer` int NOT NULL DEFAULT '0',
  `civ_wounded` tinyint NOT NULL DEFAULT '0',
  `civ_playtime` int NOT NULL DEFAULT (0),
  `dmslevel` enum('0','1','2','3','4','5','6','7','8','9','10') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `dmscomlevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `dmshammerlevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `dmsairlevel` enum('0','1','2','3') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `dms_licenses` text CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `dms_perks` text CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `dms_gear` text CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `dms_stats` varchar(25) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL DEFAULT '"[100,100,0]"',
  `dms_daily_tasks` text CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `dms_weekly_tasks` text CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `dms_arrested` tinyint NOT NULL DEFAULT '0',
  `dms_prison_timer` int NOT NULL DEFAULT '0',
  `dms_wounded` tinyint NOT NULL DEFAULT '0',
  `dms_playtime` int NOT NULL DEFAULT (0),
  `adminlevel` enum('0','1','2','3','4','5') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `eventslevel` enum('0','1','2') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `donorlevel` enum('0','1','2','3','4','5') COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  `prestige` int NOT NULL DEFAULT '0',
  `level` int NOT NULL DEFAULT '1',
  `xp` int NOT NULL DEFAULT '0',
  `reputation` int NOT NULL DEFAULT '0',
  `professions` text COLLATE utf8mb4_general_ci NOT NULL,
  `achievements` text COLLATE utf8mb4_general_ci NOT NULL,
  `titles` text COLLATE utf8mb4_general_ci NOT NULL,
  `textures` text COLLATE utf8mb4_general_ci NOT NULL,
  `blueprints` text COLLATE utf8mb4_general_ci NOT NULL,
  `insert_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `last_seen` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP ON UPDATE CURRENT_TIMESTAMP,
  PRIMARY KEY (`pid`),
  UNIQUE KEY `unique_uid` (`uid`),
  KEY `index_name` (`name`),
  KEY `index_blacklist` (`cop_blacklisted`,`med_blacklisted`) USING BTREE,
  KEY `hato_blacklisted` (`hato_blacklisted`)
) ENGINE=InnoDB AUTO_INCREMENT=3 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `players_playtime`
--

DROP TABLE IF EXISTS `players_playtime`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `players_playtime` (
  `id` int NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `cop_playtime` int NOT NULL DEFAULT '0',
  `med_playtime` int NOT NULL DEFAULT '0',
  `hato_playtime` int NOT NULL DEFAULT '0',
  `civ_playtime` int NOT NULL DEFAULT '0',
  `dms_playtime` int NOT NULL DEFAULT '0',
  `when` timestamp NOT NULL DEFAULT (now()),
  PRIMARY KEY (`id`) USING BTREE,
  KEY `FK_players_playtime` (`pid`) USING BTREE,
  CONSTRAINT `FK_players_playtime` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=98 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `settings`
--

DROP TABLE IF EXISTS `settings`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `settings` (
  `id` int NOT NULL AUTO_INCREMENT,
  `setting` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `value` varchar(300) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '0',
  PRIMARY KEY (`id`),
  UNIQUE KEY `setting` (`setting`)
) ENGINE=InnoDB AUTO_INCREMENT=22 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `vehicles`
--

DROP TABLE IF EXISTS `vehicles`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `vehicles` (
  `id` int NOT NULL AUTO_INCREMENT,
  `pid` varchar(17) COLLATE utf8mb4_general_ci NOT NULL,
  `faction` varchar(10) COLLATE utf8mb4_general_ci NOT NULL,
  `classname` varchar(64) COLLATE utf8mb4_general_ci NOT NULL,
  `type` varchar(16) COLLATE utf8mb4_general_ci NOT NULL,
  `alive` tinyint NOT NULL DEFAULT '1',
  `active` tinyint NOT NULL DEFAULT '0',
  `sold` tinyint NOT NULL DEFAULT '0',
  `impound` int NOT NULL DEFAULT '0',
  `plate` varchar(50) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '',
  `texture` varchar(50) COLLATE utf8mb4_general_ci NOT NULL DEFAULT '',
  `upgrades` text COLLATE utf8mb4_general_ci NOT NULL,
  `ignoreCondtions` tinyint NOT NULL DEFAULT (0),
  `insert_time` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  PRIMARY KEY (`id`),
  KEY `fkIdx_players_vehicles` (`pid`),
  KEY `index_type` (`type`),
  KEY `index_side` (`faction`) USING BTREE,
  CONSTRAINT `FK_players_vehicles` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB AUTO_INCREMENT=12 DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `votes`
--

DROP TABLE IF EXISTS `votes`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `votes` (
  `id` int NOT NULL AUTO_INCREMENT,
  `pid` varchar(50) COLLATE utf8mb4_general_ci DEFAULT NULL,
  `candidate` int DEFAULT NULL,
  `amount` int DEFAULT '1',
  `active` tinyint DEFAULT '1',
  PRIMARY KEY (`id`),
  UNIQUE KEY `pid` (`pid`),
  KEY `FK_votes_candidates` (`candidate`),
  CONSTRAINT `FK_votes_candidates` FOREIGN KEY (`candidate`) REFERENCES `candidates` (`id`) ON DELETE CASCADE ON UPDATE CASCADE,
  CONSTRAINT `FK_votes_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Table structure for table `warrants`
--

DROP TABLE IF EXISTS `warrants`;
/*!40101 SET @saved_cs_client     = @@character_set_client */;
/*!50503 SET character_set_client = utf8mb4 */;
CREATE TABLE `warrants` (
  `id` int NOT NULL AUTO_INCREMENT,
  `pid` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `faction` varchar(10) CHARACTER SET utf8mb4 COLLATE utf8mb4_general_ci NOT NULL,
  `act` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `crime` varchar(50) COLLATE utf8mb4_general_ci NOT NULL,
  `info` text COLLATE utf8mb4_general_ci NOT NULL,
  `insert` timestamp NOT NULL DEFAULT CURRENT_TIMESTAMP,
  `active` tinyint NOT NULL DEFAULT '1',
  PRIMARY KEY (`id`),
  KEY `FK_warrants_players` (`pid`),
  KEY `faction` (`faction`),
  CONSTRAINT `FK_warrants_players` FOREIGN KEY (`pid`) REFERENCES `players` (`pid`) ON DELETE CASCADE ON UPDATE CASCADE
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;
/*!40101 SET character_set_client = @saved_cs_client */;

--
-- Dumping events for database 'altislife'
--

--
-- Dumping routines for database 'altislife'
--
/*!50003 DROP PROCEDURE IF EXISTS `decreaseHousingUpKeepDays` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`arma`@`localhost` PROCEDURE `decreaseHousingUpKeepDays`()
BEGIN

	UPDATE `houses` SET `upkeepDaysLeft` = `upkeepDaysLeft` - 1 WHERE `upkeepDaysLeft` > 0;

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `decreaseMailDaysUntilExpiry` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`arma`@`localhost` PROCEDURE `decreaseMailDaysUntilExpiry`()
BEGIN

	UPDATE `mail` SET `daysUntilExpiry` = `daysUntilExpiry` - 1 WHERE `daysUntilExpiry` IS NOT NULL AND `daysUntilExpiry` > 0;

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `deleteOldAlliances` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`arma`@`localhost` PROCEDURE `deleteOldAlliances`()
BEGIN

	DELETE FROM `group_alliances` WHERE `active` = '0';

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `deleteOldBaseBids` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `deleteOldBaseBids`()
BEGIN
	DELETE FROM base_bids WHERE active='0';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `deleteOldCommunityGoals` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `deleteOldCommunityGoals`()
BEGIN
	DELETE FROM community_goals WHERE end_date <= CURDATE();
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `deleteOldElection` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `deleteOldElection`()
BEGIN
	DELETE FROM votes WHERE active='0';
	DELETE FROM candidates WHERE active='0';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `deleteOldGroups` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `deleteOldGroups`()
BEGIN
	DELETE FROM `groups` WHERE active='0';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `deleteOldHouses` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `deleteOldHouses`()
BEGIN
	DELETE FROM houses WHERE sold='1';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `deleteOldMail` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `deleteOldMail`()
BEGIN
	DELETE FROM mail WHERE `claimed`='1' OR `daysUntilExpiry` IS NOT NULL AND `daysUntilExpiry` <= 0;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `deleteOldWarrants` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `deleteOldWarrants`()
BEGIN
	DELETE FROM warrants WHERE active='0';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `processPlaytime` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`arma`@`localhost` PROCEDURE `processPlaytime`()
BEGIN

	INSERT INTO `players_playtime` (`pid`, `cop_playtime`, `med_playtime`, `hato_playtime`, `civ_playtime`, `dms_playtime`)

		SELECT `pid`, `cop_playtime`, `med_playtime`, `hato_playtime`, `civ_playtime`, `dms_playtime` FROM `players`;

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `resetDailyGoals` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `resetDailyGoals`()
BEGIN
	UPDATE players SET cop_daily_tasks = '"[]"';
  UPDATE players SET med_daily_tasks = '"[]"';
  UPDATE players SET hato_daily_tasks = '"[]"';
  UPDATE players SET civ_daily_tasks = '"[]"';
	UPDATE settings SET `value`=DATE_FORMAT(CURDATE(), '%Y-%c-%e') WHERE setting = 'Day';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `resetGroupBuffs` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `resetGroupBuffs`()
BEGIN
	UPDATE `groups` SET buffs = '"[]"';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `resetVehicles` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `resetVehicles`()
BEGIN
	UPDATE vehicles SET `active`='0';
	DELETE FROM vehicles WHERE sold='1';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `resetWeeklyGoals` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `resetWeeklyGoals`()
BEGIN
	UPDATE players SET cop_weekly_tasks = '"[]"';
  UPDATE players SET med_weekly_tasks = '"[]"';
  UPDATE players SET hato_weekly_tasks = '"[]"';
  UPDATE players SET civ_weekly_tasks = '"[]"';
	UPDATE settings SET `value`=WEEK(CURDATE()) WHERE setting = 'Week';
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `resetWoundedPlayers` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_general_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`arma`@`localhost` PROCEDURE `resetWoundedPlayers`()
BEGIN

	UPDATE `players` SET `cop_wounded`='0', `med_wounded`='0', `hato_wounded`='0', `civ_wounded`='0';

END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!50003 DROP PROCEDURE IF EXISTS `sortPremiumGroups` */;
/*!50003 SET @saved_cs_client      = @@character_set_client */ ;
/*!50003 SET @saved_cs_results     = @@character_set_results */ ;
/*!50003 SET @saved_col_connection = @@collation_connection */ ;
/*!50003 SET character_set_client  = utf8mb4 */ ;
/*!50003 SET character_set_results = utf8mb4 */ ;
/*!50003 SET collation_connection  = utf8mb4_0900_ai_ci */ ;
/*!50003 SET @saved_sql_mode       = @@sql_mode */ ;
/*!50003 SET sql_mode              = 'ONLY_FULL_GROUP_BY,STRICT_TRANS_TABLES,NO_ZERO_IN_DATE,NO_ZERO_DATE,ERROR_FOR_DIVISION_BY_ZERO,NO_ENGINE_SUBSTITUTION' */ ;
DELIMITER ;;
CREATE DEFINER=`root`@`localhost` PROCEDURE `sortPremiumGroups`()
BEGIN
	UPDATE `groups` SET premium = '0' WHERE premium = '1' AND CURRENT_TIMESTAMP() > premium_expire;
END ;;
DELIMITER ;
/*!50003 SET sql_mode              = @saved_sql_mode */ ;
/*!50003 SET character_set_client  = @saved_cs_client */ ;
/*!50003 SET character_set_results = @saved_cs_results */ ;
/*!50003 SET collation_connection  = @saved_col_connection */ ;
/*!40103 SET TIME_ZONE=@OLD_TIME_ZONE */;

/*!40101 SET SQL_MODE=@OLD_SQL_MODE */;
/*!40014 SET FOREIGN_KEY_CHECKS=@OLD_FOREIGN_KEY_CHECKS */;
/*!40014 SET UNIQUE_CHECKS=@OLD_UNIQUE_CHECKS */;
/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
/*!40111 SET SQL_NOTES=@OLD_SQL_NOTES */;

-- Dump completed on 2025-08-15 17:19:32

--
-- Dumping data for table `settings`
--

LOCK TABLES `settings` WRITE;
/*!40000 ALTER TABLE `settings` DISABLE KEYS */;
INSERT INTO `settings` VALUES (1,'base_owner_North','-1'),(2,'base_owner_South','-1'),(10,'DonationGoal','0'),(11,'ThreatLevel','0'),(12,'Day','2025-6-21'),(13,'Week','24'),(14,'Governor','\"[]\"'),(15,'GovernorSettings','\"[]\"'),(16,'Election','0'),(17,'NextElection','2025-3-1'),(18,'BaseBidsActive','0'),(19,'NextSeason','2025-3-24'),(20,'Season','1'),(21,'CasinoVault','100000');
/*!40000 ALTER TABLE `settings` ENABLE KEYS */;
UNLOCK TABLES;