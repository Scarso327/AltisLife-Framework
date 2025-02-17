USE `altislife`;

CREATE TABLE `group_alliances` (
	`id` INT NOT NULL AUTO_INCREMENT,
	`group_a_id` INT NOT NULL,
	`group_b_id` INT NOT NULL,
	`active` TINYINT NOT NULL DEFAULT '1',
	UNIQUE INDEX `IDX_UNIQUE_PAIR` (`group_a_id`, `group_b_id`) USING BTREE,
	INDEX `id` (`id`) USING BTREE,
	INDEX `FK_GROUP_B` (`group_b_id`) USING BTREE,
	CONSTRAINT `FK_GROUP_A` FOREIGN KEY (`group_a_id`) REFERENCES `groups` (`id`) ON UPDATE RESTRICT ON DELETE CASCADE,
	CONSTRAINT `FK_GROUP_B` FOREIGN KEY (`group_b_id`) REFERENCES `groups` (`id`) ON UPDATE RESTRICT ON DELETE CASCADE
)
COLLATE='utf8mb4_general_ci'
ENGINE=InnoDB
;

DELIMITER //
CREATE PROCEDURE `deleteOldAlliances`()
BEGIN
	DELETE FROM `group_alliances` WHERE `active` = '0';
END//
DELIMITER ;