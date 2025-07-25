import Data.Time

main :: IO ()
main = do 
  !startTime <- getCurrentTime
  let !result = solution
  !endTime <- getCurrentTime
  let diffTime = diffUTCTime endTime startTime
  --putStrLn ("Solution: " ++ (show result))
  --putStrLn ("Execution Time: " ++ (show diffTime))
  putStrLn $ (reverse.tail.reverse) (show diffTime)

solution :: Int
solution = grid size size

grid :: Int -> Int -> Int
grid 1 l = l + 1
grid r 1 = r + 1
grid r l = mem!!(r-1)!!l + mem!!r!!(l-1)

mem :: [[Int]]
mem = [[grid l r | l <- [0..size]] | r <- [0..size]]

size :: Int
size = 20
