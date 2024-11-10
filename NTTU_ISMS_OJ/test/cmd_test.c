#include <stdio.h>
#include <string.h>

int run_cmd(const char * cmd)
{
	char MsgBuff[1024];
	int MsgLen=1020;
	FILE * fp;
	if (cmd == NULL)
	{
		return -1;
	}
	if ((fp = _popen(cmd, "r")) == NULL)
	{
		return -2;
	}
	else
	{
		memset(MsgBuff, 0, MsgLen);

		//读取命令执行过程中的输出
		while (fgets(MsgBuff, MsgLen, fp) != NULL)
		{
			printf("_MsgBuff: %s\n", MsgBuff);
		}

		//关闭执行的进程
		if(_pclose(fp) == -1)
		{
			return -3;
		}
	}
	return 0;
}

int main()
{
	//const char *cmd = "ffmpeg -i D:\\123.mp4 -vf reverse D:\\out\\out1.mp4";
	
	const char *cmd = "ping www.baidu.com";
	int ret = 0;
	ret = run_cmd(cmd);
	printf("cmd:%d\r\n",ret);

	// getchar();
	return 0;
}
