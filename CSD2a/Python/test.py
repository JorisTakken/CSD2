async def seq():
    a = 1
    while a < (1 + hoevaakLoopen):
        i = 1
        while i < (1 + hoeveelKeerSpelen):
            for i in sample:
                asyncio.create_task(asyncio.sleep(1))
            
                if welkeSampleInput == "kick":
                    print("kick")
                if welkeSampleInput == "schreeuw":
                    print("schreeuw")
                
                welkeSample.play()
                await asyncio.sleep(BPM/i)

          
            i += 1
            if i < (hoeveelKeerSpelen + 1): 
                print("------------")  
        a += 1
        if a < (hoevaakLoopen + 1):
            print("ja stop maar!")
            welkeSample.stop()