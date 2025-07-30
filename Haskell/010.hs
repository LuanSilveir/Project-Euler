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
solution = sum $ 2:(filter isPrime [3,5..2000000])

isPrime :: Int -> Bool
isPrime n = all (\x -> n `mod` x /= 0) [2..(floor.sqrt.fromIntegral) n + 1]
