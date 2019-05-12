CREATE TABLE `question` (
  `id` int(11) NOT NULL COMMENT '题目号',
  `name` varchar(255) NOT NULL COMMENT '题目名字',
  `level` enum('简单','中等','较难') NOT NULL COMMENT '题目难易程度',
  `question_describe` text NOT NULL COMMENT '题目描述',
  `code_structure` text COMMENT '代码框架',
  PRIMARY KEY (`id`)
) ENGINE=InnoDB DEFAULT CHARSET=utf8;

