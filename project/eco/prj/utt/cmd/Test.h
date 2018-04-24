#ifndef ECO_CMD_TEST_H
#define ECO_CMD_TEST_H
/*******************************************************************************
@ 名称

@ 功能

@ 异常

@ 备注

--------------------------------------------------------------------------------
@ 历史记录 @
@ ujoy modifyed on 2016-10-29

--------------------------------------------------------------------------------
* 版权所有(c) 2015 - 2017, ujoychou, 保留所有权利。

*******************************************************************************/
#include <eco/App.h>


namespace eco{;
namespace cmd{;
namespace test{;


////////////////////////////////////////////////////////////////////////////////
class Cmd1 : public eco::cmd::Command
{
	ECO_COMMAND(Cmd1, "cmd1", "c1");
public:
	virtual void execute(
		IN const Context& context) override;

	static const char* get_help_info();
};


////////////////////////////////////////////////////////////////////////////////
class Cmd2 : public eco::cmd::Command
{
	ECO_COMMAND(Cmd2, "cmd2", "c2");
public:
	virtual void execute(
		IN const eco::cmd::Context& context) override;
};


////////////////////////////////////////////////////////////////////////////////
class Cmd7 : public eco::cmd::Command
{
	ECO_COMMAND(Cmd7, "cmd7", "c7");
public:
	virtual void execute(
		IN const eco::cmd::Context& context) override;
};


////////////////////////////////////////////////////////////////////////////////
class Cmd8 : public eco::cmd::Command
{
	ECO_COMMAND(Cmd8, "cmd8", "c8");
public:
	virtual void execute(
		IN const eco::cmd::Context& context) override;
};


////////////////////////////////////////////////////////////////////////////////
class Cmd9 : public eco::cmd::Command
{
	ECO_COMMAND(Cmd9, "cmd9", "c9");
public:
	virtual void execute(
		IN const eco::cmd::Context& context) override;
};



////////////////////////////////////////////////////////////////////////////////
class Manager
{
	ECO_SINGLETON(Manager);
public:
	static void cmd3(
		IN const eco::cmd::Context& context,
		IN eco::cmd::ExecuteMode mode);
	static void cmd4(
		IN const eco::cmd::Context& context,
		IN eco::cmd::ExecuteMode mode);

public:
	void cmd5(
		IN const eco::cmd::Context& context,
		IN eco::cmd::ExecuteMode mode);
	void cmd6(
		IN const eco::cmd::Context& context,
		IN eco::cmd::ExecuteMode mode);
};
ECO_SINGLETON_GET(Manager);




}}}
#endif