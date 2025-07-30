import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  putStrLn ("Solution: " ++ (show result))
  putStrLn ("Execution Time: " ++ (show diffTime))
  --putStrLn $ (reverse.tail.reverse) (show diffTime)

solution :: Int
solution = (sum . filter even) (fibseq [2,1])

fibseq :: [Int] -> [Int]
fibseq (x:y:zs) = if s < 4000000 then fibseq (s:x:y:zs) else (x:y:zs) where s = x+y

