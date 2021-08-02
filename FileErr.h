//操作错误类，声明报错的函数

#pragma once
#ifndef FILEERR_H
#define FILEERR_H

class FileErr
{
public:

	int reasonopen() const;
	int reasonread() const;
};

#endif // !FILEERR_H
