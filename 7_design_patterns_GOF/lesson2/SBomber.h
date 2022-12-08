#pragma once

#include <vector>

#include "LevelGUI.h"
#include "Plane.h"
#include "Bomb.h"
#include "Ground.h"
#include "Tank.h"

class SBomber
{
public:

    SBomber();
    ~SBomber();
    
    inline bool GetExitFlag() const { return exitFlag; }

    void ProcessKBHit();
    void TimeStart();
    void TimeFinish();

    void DrawFrame();
    void MoveObjects();
    void CheckObjects();

private:
    void CheckPlaneAndLevelGUI();
    void CheckBombsAndGround();
    void __fastcall CheckDestoyableObjects(Bomb* pBomb);

    void __fastcall DeleteDynamicObj(DynamicObject * pBomb);
    void __fastcall DeleteStaticObj(GameObject* pObj);

    Ground * FindGround() const;
    Plane * FindPlane() const;
    LevelGUI * FindLevelGUI() const;
    std::vector<DestroyableGroundObject*> FindDestoyableGroundObjects() const;
    std::vector<Bomb*> FindAllBombs() const;

    void DropBomb();

    std::vector<DynamicObject*> vecDynamicObj;
    std::vector<GameObject*> vecStaticObj;
    
    bool exitFlag;

    uint64_t startTime, finishTime, passedTime;
    uint16_t bombsNumber, deltaTime, fps;
    int16_t score;
};

///////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////// Command ////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////////////
class AbstractCommand
{
protected:
    SBomber* sbomb;
public:
    virtual ~AbstractCommand() {}
    virtual void Execute() = 0;
    void setSBomber(SBomber* _sbomb)
    {
        sbomb = _sbomb;
    }
};


class DeleteDynamicObjCommand :public AbstractCommand
{
private:
    DynamicObject* _pObj;
    std::vector<DynamicObject*>* _vDynamicObj;
public:
    DeleteDynamicObjCommand(DynamicObject*, std::vector<DynamicObject*>&);
    void Execute() override;
};


class DeleteStaticObjCommand :public AbstractCommand
{
private:
    GameObject* _pObj;
    std::vector<GameObject*>* _vStaticObj;
public:
    DeleteStaticObjCommand(GameObject*, std::vector<GameObject*>&);
    void Execute() override;
};


class DropBomb :public AbstractCommand
{
private:
    const Plane* _pl;
    std::vector<DynamicObject*> *_vDynamicObj;
    uint16_t _bombsNumber;
    const int16_t *_score;
public:
    DropBomb(const Plane* pl, vector<DynamicObject*>& vDinObj, uint16_t bomNum, const int16_t* score);
    void Execute();
};


class commandExecuter
{
private:
    AbstractCommand* aCommand;
    SBomber sbomb;
public:
    ~commandExecuter()
    {
        delete aCommand;
    }

    void DeleteDynamicObj(DynamicObject*, std::vector<DynamicObject*>&);

    void DeleteStaticObj(GameObject*, std::vector<GameObject*>& vStaticObj);

    void DropBom(const Plane*, vector<DynamicObject*>&, uint16_t, const int16_t*);
};