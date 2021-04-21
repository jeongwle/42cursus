//*****설명을 위한 주석처리모드*****//


#include "mlx/mlx.h"	//mlx 헤더추가 (open_gl	헤더로 교체)
#include "key_macos.h"	//키 값 넣은 헤더추가

#include <math.h>	//회전행렬 계산을 위해 추가
#include <string.h>	
#include <stdio.h>
#include <stdlib.h>	
#define X_EVENT_KEY_PRESS	2	//키프레스를 위한 2 (키가 눌렸을때의 값)
#define X_EVENT_KEY_EXIT	17	
#define mapWidth 24			//맵 넓이
#define mapHeight 24			//맵 높이
#define width 640			//스크린넓이
#define height 480			//스크린 높이
	
typedef struct	s_info			//구조체(전반적인 변수들에 대한 구조체)
{
	double posX;			//플레이어의 X축위치
	double posY;			//플레이어의 Y축위
	double dirX;			//플레이어가 보는방향벡터 X벡터
	double dirY;			//플레이어가 보는방향벡터 y벡터
	double planeX;			//플레이어가 보는 쪽 카메라 평면 x
	double planeY;			//플레이어가 보는 쪽 카메라 평면 y
	void	*mlx;			//mlx함수사용 mlx변수
	void	*win;			//mlx함수사용 윈도우변수
	double	moveSpeed;		//플레이어 이동속도
	double	rotSpeed;		//플레이어 회전행렬 세타 (사인,코사인 세타의 세타값)
}				t_info;
	
int	worldMap[24][24] = {	//맵 그림
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,2,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,3,0,0,0,3,0,0,0,1},
	{1,0,0,0,0,0,2,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,2,2,0,2,2,0,0,0,0,3,0,3,0,3,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,5,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,0,0,0,0,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,4,4,4,4,4,4,4,4,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1}
};
	
void	verLine(t_info *info, int x, int y1, int y2, int color)		//벽을 세로축으로 그리기 위한 함수(vertical line의줄임말)
									//여기서 y1과 y2는 밑에서 구하는 drawstart랑 drawend임니다.
{
	int	y;							//y변수

	y = y1;								//외부에서 생성된 y1 대입(변화되기때문에 y변수로 지정 후 대입)
	while (y <= y2)							//y1 ~ y2까지
	{
		mlx_pixel_put(info->mlx, info->win, x, y, color);	//이미지put으로 변화가능
		y++;							//y증가
	}
}
	
void	calc(t_info *info)						//벽생성계산하는 함수
{
	int	x;							//스크린 넓이로 상승하는 x변수
	
	x = 0;
	while (x < width)
	{
		double cameraX = 2 * x / (double)width - 1;		//카메라X 
		double rayDirX = info->dirX + info->planeX * cameraX;	//광선방향벡터의 x벡터 계산
		double rayDirY = info->dirY + info->planeY * cameraX;	//광선방향벡터의 y벡터 계산
	
		int mapX = (int)info->posX;				//현재 플레이어가 있는 맵상의 x 위치
		int mapY = (int)info->posY;				//현재 플레이어가 있는 맵상의 y 위치
	
		//현재위치에서 다음 x면 또는 y면까지의 거리를 나타내는 변수
		double sideDistX;
		double sideDistY;
		
		//현재의 x면 또는 y면으로부터 다음 x면이나 y면까지의 거리를 나타내는 변
		double deltaDistX = fabs(1 / rayDirX);			//*fabs = 절대값연산함
		double deltaDistY = fabs(1 / rayDirY);
		double perpWallDist;					//벽까지의 거리를 나탸내는 변수
	
		//what direction to step in x or y-direction (either +1 or -1)		//x나 y방향으로 가는 지에 따른 한번이동하는 스탭(1이나 -1)
		int stepX;
		int stepY;
	
		int hit = 0; //was there a wall hit?				//벽하고 부딪힘?
		int side; //was a NS or a EW wall hit?				//북.남쪽 방향벽인지 동.서쪽 방향벽인지 확인하는 플래그 변수
	
		if (rayDirX < 0)						//x축 레이저방향벡터가 0보다 작으면
		{
			stepX = -1;						//x스텝 -1
			sideDistX = (info->posX - mapX) * deltaDistX;		//다음 x면까지의 공식
		}
		else								//x축 레이저방향벡터가 0보다 큼
		{
			stepX = 1;						//x스텝 1
			sideDistX = (mapX + 1.0 - info->posX) * deltaDistX;	//다음 x면까지의 공식
		}
		if (rayDirY < 0)						//y축 레이저방향벡터가 0보다 작으면
		{
			stepY = -1;						//y스텝 -1
			sideDistY = (info->posY - mapY) * deltaDistY;		//다음 y면까지의 공식
		}
		else								//y축 레이저방향벡터가 0보다 크면
		{
			stepY = 1;						//스텝 1
			sideDistY = (mapY + 1.0 - info->posY) * deltaDistY;	//다음 y면까지의 공식
		}
	
		while (hit == 0)							//벽이 발견되지  않을동안 반복문
		{
			//jump to next map square, OR in x-direction, OR in y-direction	//x방향 또는 y방향으로 맵의 다음 사각형으로 점핑
			if (sideDistX < sideDistY)					//y면으로 가는 길이가 x면으로 가는 길이보다 더 크면
			{
				sideDistX += deltaDistX;				
				mapX += stepX;						//멥의 x측으로 스텝 x증가
				side = 0;						//남쪽, 북쪽일때 side = 0
			}
			else								//y면으로 가는 길이가 x면으로 가는 길이보다 더 작으면
			{
				sideDistY += deltaDistY;
				mapY += stepY;						//맵의 y측으로 스텝 y증가
				side = 1;						//동쪽, 서쪽일때 side = 1
			}
			//Check if ray has hit a wall
			if (worldMap[mapX][mapY] > 0) hit = 1;				//벽에 부딪힘? 안부딪힘?
		}
		if (side == 0)								//남쪽이나 북쪽임까?
			perpWallDist = (mapX - info->posX + (1 - stepX) / 2) / rayDirX;	//벽까지의 거리를 나타내는 변수공식
		else									//동쪽이나 서쪽임까?
			perpWallDist = (mapY - info->posY + (1 - stepY) / 2) / rayDirY;	//벽까지의 거리를 나타내는 변수공식
	
		//Calculate height of line to draw on screen				//벽 높이를 계산하는 법!
		int lineHeight = (int)(height / perpWallDist);
	
		//calculate lowest and highest pixel to fill in current stripe		//벽의 맨 윗점(시작점)과 맨 아랫점(끝점)계산
		int drawStart = -lineHeight / 2 + height / 2;				//벽의 맨 윗점 계산하는법
		if(drawStart < 0)							//벽의 시작점이 0보다 작으면(안되겠죠?)
			drawStart = 0;							//그롬 0으로 만듭니다.
		int drawEnd = lineHeight / 2 + height / 2;				//벽의 끝점 계산하는 법
		if(drawEnd >= height)							//벽이 스크린 높이값하고 같거나 크면 (화면 전체가득)
			drawEnd = height - 1;						//스크린 높이값에서 1을 뺀다. (1을 안빼면 세그로 터지기때문)
	
		int	color;								//벽 색깔 정하는 색깔변수
		if (worldMap[mapY][mapX] == 1)						//만약에 맵이 1 (벽 1)
			color = 0xFF0000;						//빨간색
		else if (worldMap[mapY][mapX] == 2)					//맵이 2(벽 2)
			color = 0x00FF00;						//초록색
		else if (worldMap[mapY][mapX] == 3)					//맵이 3(벽 3)
			color = 0x0000FF;						//파란색
		else if (worldMap[mapY][mapX] == 4)					//맵이 4(벽 4)
			color = 0xFFFFFF;						//하얀색
		else
			color = 0xFFFF00;						//노랑색
	
		if (side == 1)								//만약에 동쪽이나 서쪽이면?
			color = color / 2;						//컬러 반토막 (아마 이거 명함때문이던가..뭐더라..사실난안씀)
	
		verLine(info, x, drawStart, drawEnd, color);				//아까 만들어놨던 수직라인함수
	
		x++;
	}
}
	
int	main_loop(t_info *info)								//메인루프 (루프 훅으로 계속 돌릴라고)
{
	calc(info);									//벽 높이랑 기타등등 계산한 함수 (계속 루프로 돌림)
	// mlx_put_image_to_window(info->mlx, info->win, &info->img, 0, 0);		//이미지 파일로 쓸때 쓰는거(여긴 픽셀이라서 주석처리중)
	
	return (0);
}
	
int	key_press(int key, t_info *info)								//키 입력에 대한부분
{
	if (key == K_W)											//앞쪽키
	{
		if (!worldMap[(int)(info->posX + info->dirX * info->moveSpeed)][(int)(info->posY)])	//벽에 붙어있으면 빗겨가게 만드는 이프문
			info->posX += info->dirX * info->moveSpeed;					//걍 이동하는건데 (속도제어변수 곱함)
		if (!worldMap[(int)(info->posX)][(int)(info->posY + info->dirY * info->moveSpeed)])	//벽에 붙어있으면 빗겨가게 만드는 이프문

			info->posY += info->dirY * info->moveSpeed;
	}
	//move backwards if no wall behind you								//뒤쪽키
	if (key == K_S)
	{
		if (!worldMap[(int)(info->posX - info->dirX * info->moveSpeed)][(int)(info->posY)])	//벽에 붙어있으면 빗겨가게 만드는 이프문

			info->posX -= info->dirX * info->moveSpeed;					//걍 이동하는건데 (속도제어변수 곱함)

		if (!worldMap[(int)(info->posX)][(int)(info->posY - info->dirY * info->moveSpeed)])	//벽에 붙어있으면 빗겨가게 만드는 이프문

			info->posY -= info->dirY * info->moveSpeed;					//걍 이동하는건데 (속도제어변수 곱함)

	}
	//rotate to the right
	if (key == K_D)											//오른쪽 회전키
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(-info->rotSpeed) - info->dirY * sin(-info->rotSpeed);	//회전행렬 곱
		info->dirY = oldDirX * sin(-info->rotSpeed) + info->dirY * cos(-info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(-info->rotSpeed) - info->planeY * sin(-info->rotSpeed);
		info->planeY = oldPlaneX * sin(-info->rotSpeed) + info->planeY * cos(-info->rotSpeed);
	}
	//rotate to the left
	if (key == K_A)											//왼쪽 회전키
	{
		//both camera direction and camera plane must be rotated
		double oldDirX = info->dirX;
		info->dirX = info->dirX * cos(info->rotSpeed) - info->dirY * sin(info->rotSpeed);	//회전행렬곱
		info->dirY = oldDirX * sin(info->rotSpeed) + info->dirY * cos(info->rotSpeed);
		double oldPlaneX = info->planeX;
		info->planeX = info->planeX * cos(info->rotSpeed) - info->planeY * sin(info->rotSpeed);
		info->planeY = oldPlaneX * sin(info->rotSpeed) + info->planeY * cos(info->rotSpeed);
	}
	if (key == K_ESC)										//esc 입력 (윈도우창 꺼짐)
		exit(0);
	return (0);
}
	
int	main(void)
{
	t_info info;
	info.mlx = mlx_init();
	
	info.posX = 12;							//플레이어 x위치
	info.posY = 5;							//플레이어 y위치
	info.dirX = -1;							//방향벡터 x -1 (북쪽)
	info.dirY = 0;							//방향백터 y 0 
	info.planeX = 0;						//x 평면 0
	info.planeY = 0.66;						//y 평면 (시야각 66도)
	info.moveSpeed = 0.05;						//플레이어이동속도
	info.rotSpeed = 0.05;						//회전 각 (라디안 값 <여기서는 임의 설정값>)
	
	info.win = mlx_new_window(info.mlx, width, height, "mlx");	//윈도우창 열고

	mlx_loop_hook(info.mlx, &main_loop, &info);			//루프훅 : 계속해서 변화가 생길때마다 함수들 돌려벌임
	mlx_hook(info.win, X_EVENT_KEY_PRESS, 0, &key_press, &info);	//훅 : 어떤 변화에 따라서 계속 수행되는 단일성행동들
	
	mlx_loop(info.mlx);						//루프 : 계속 실행중...
}

